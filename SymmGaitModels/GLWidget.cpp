#include "GLWidget.h"

struct GLWidget::Point {
	GLfloat x;
	GLfloat y;
};

  // //////////////////////////////////////////////////////////////////////////////
 // PUBLIC METHODS /////////// PUBLIC METHODS ////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////
GLWidget::~GLWidget() {
	delete[] plot;
}

GLWidget::GLWidget(QWidget * parent = 0) : QOpenGLWidget(parent)
{
	this->mds = new Engine::Matrix("Resources/dpm/DPM_1_f003BMEDc.txt",
		Engine::MDS_COL_NO, Engine::MDS_ROW_NO);
	rotatex = 0.0;
	rotatey = 0.0;
	paintedColumn = 0;
}

void GLWidget::setPaintedColumn(int markerNr, int coord) {
	paintedColumn = (markerNr - 1) * 3 + (coord - 1);
}

void GLWidget::readMatrixFromFile(const char* fileName) {
	delete mds;
	mds = new Engine::Matrix(fileName, Engine::MDS_COL_NO, Engine::MDS_ROW_NO);
}
  // /////////////////////////////////////////////////////////////////////////////
 // OVERLOADED METHODS //////////////// OVERLOADED METHODS //////////////////////
// /////////////////////////////////////////////////////////////////////////////
void GLWidget::initializeGL() {
	initializeOpenGLFunctions();
	glEnable(GL_POINT_SPRITE);
	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	vertexShad = new QOpenGLShader(QOpenGLShader::Vertex);
	fragmentShad = new QOpenGLShader(QOpenGLShader::Fragment);

	bool flag = vertexShad->compileSourceCode(vertexShadSrc);
	if (flag) printf("compiled vertex Shader\n");
	flag = fragmentShad->compileSourceCode(fragmentShadSrc);
	if (flag) printf("compiled fragment Shader\n");
	flag = program.addShader(vertexShad);
	if (flag) printf("linked vertex Shader\n");
	flag = false;
	flag =program.addShader(fragmentShad);
	if (flag) printf("linked fragment Shader\n");

	program.link();
	program.bind();
}

void GLWidget::paintGL() {
	int margin = 30; // @TODO put it as constant class member
	glViewport(margin, margin, this->width() - margin * 2, this->height() - margin * 2);
	glScissor(margin, margin, this->width() - margin * 2, this->height() - margin * 2);
	glEnable(GL_SCISSOR_TEST);

	prepareData2D();
	findScaleAndOffset();
	paintPlot2D();
	drawZeroRule2D();
}

void GLWidget::resizeGL(int width, int height) {
	glViewport(0,0, width, height);
}
  // ////////////////////////////////////////////////////////////
 //  PRIVATE methods  //////////////// PRIVATE METHODS /////////
// ////////////////////////////////////////////////////////////
void GLWidget::prepareData2D() {
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	plotSize = 100;
	plot = new Point[plotSize];
	for (int i = 0; i < plotSize; ++i) {
		plot[i].x = i;
		plot[i].y = mds->operator()(paintedColumn, i);
	}
	glBufferData(GL_ARRAY_BUFFER, plotSize * sizeof Point, plot, GL_STATIC_DRAW);
}

void GLWidget::paintPlot2D() {
	// attributes to Vertex Shad
	this->coord2d = program.attributeLocation("coord2d");
	program.enableAttributeArray(coord2d);
	program.setAttributeValue("coord2d", coord2d);
	program.setUniformValue("offsetX", GLfloat(plotSize/2));
	program.setUniformValue("scaleX", GLfloat(plotSize / 2));
	program.setUniformValue("scaleY", scaleY);
	program.setUniformValue("offsetY", offsetY);
	// attributes to Fragment Shad
	program.setUniformValueArray("f_color", PlotColor::RED, 1, 4);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(coord2d);
	glVertexAttribPointer(
		coord2d,   // attribute
		2,                   // number of elements per vertex, here (x,y)
		GL_FLOAT,            // the type of each element
		GL_FALSE,            // take our values as-is
		0,                   // no space between values
		0                    // use the vertex buffer object
		);
	glDrawArrays(GL_LINE_STRIP, 0, 100);
	drawPoints2D();
	// CLEANING
	glDisableVertexAttribArray(coord2d);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void GLWidget::drawPoints2D(float pSize) {
	glPointSize(pSize);
	glDrawArrays(GL_POINTS, 0, 100);
}

void GLWidget::writeMatToFile(const char * fileName) {
	std::fstream file;
	file.open(fileName, std::ios::out);
	file << (*mds);
	file.close();
}

void GLWidget::drawZeroRule2D() {
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	Point zeroRule[2];
	zeroRule[0].x = 0.0;   zeroRule[0].y = 0.0;
	zeroRule[1].x = 100.0; zeroRule[1].y = 0.0;
	glBufferData(GL_ARRAY_BUFFER, 2 * sizeof Point, zeroRule, GL_STATIC_DRAW);
	program.setUniformValueArray("f_color", PlotColor::BLACK, 1, 4);
	this->coord2d = program.attributeLocation("coord2d");
	program.enableAttributeArray(coord2d);
	program.setAttributeValue("coord2d", coord2d);
	glEnableVertexAttribArray(coord2d);
	glVertexAttribPointer(coord2d,2, GL_FLOAT, GL_FALSE, 0, 0 );
	glDrawArrays(GL_LINE_STRIP, 0, 2);
	// Cleaning
	glDisableVertexAttribArray(coord2d);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void GLWidget::findScaleAndOffset() { // TODO add sample scale
	if (NULL == plot) {
		printf("Error!!! The plot has not been initialized yet!!!\n");
		/// @TODO throw an exception here
	}
	float maxY = plot[0].y;
	float minY = plot[0].y;
	offsetY = 0.0;
	for (int i = 0; i < plotSize; ++i) {
		offsetY += plot[i].y;
		if (maxY < plot[i].y) {
			maxY = plot[i].y;
		}
		if (minY > plot[i].y) {
			minY = plot[i].y;
		}
	}
	printf("offset: %f\n", offsetY);
	offsetY = offsetY / 100.0;
	if (maxY >= 0.0 && minY <= 0.0) { // max is above zero, min is below zero
		if (offsetY >= 0.0) { // max and average is above zero, min below
			if (maxY - offsetY > abs(minY) + offsetY)
				scaleY = maxY - offsetY;
			else
				scaleY = abs(minY) + offsetY;
		}
		else { // max is above zero, average and min are below zero
			if (maxY - offsetY > abs(minY) - abs(offsetY))
				scaleY = maxY - offsetY;
			else
				scaleY = abs(minY) - abs(offsetY);
		}
	}
	else {
		if (abs(abs(maxY) - abs(offsetY)) > abs(abs(offsetY) - abs(minY))) {
			scaleY = abs(abs(maxY) - abs(offsetY));
		}
		else {
			scaleY = abs(abs(offsetY) - abs(minY));
		}
	}
	printf("scale: %f \noffset: %f \n", scaleY, offsetY);
}

