#include "GLWidget.h"

struct GLWidget::Point {
	GLfloat x;
	GLfloat y;
};

GLWidget::GLWidget(QWidget * parent = 0) : QOpenGLWidget(parent)
{
	rotatex = 0.0;
	rotatey = 0.0;
}

void GLWidget::initializeGL() {
	initializeOpenGLFunctions();
	glEnable(GL_POINT_SPRITE);
	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	plotSize = 100;
	plot = new Point[plotSize];
	for (int i = 0; i < plotSize; ++i) {
		float x = i;//(i-50)/50.0;
		plot[i].x = x;
		plot[i].y = 15 * sin(x/8* 3.14);
	}
	glBufferData(GL_ARRAY_BUFFER, plotSize * sizeof Point, plot, GL_STATIC_DRAW);

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
	paintPlot2D();
}

void GLWidget::resizeGL(int width, int height) {
	glViewport(0,0, width, height);
}

//PRIVATE methods

void GLWidget::paintPlot2D() {
	int margin = 30; // @TODO put it as constant class member
	glViewport(margin, margin, this->width()-margin*2, this->height()-margin*2);
	glScissor(margin ,margin , this->width()-margin*2, this->height() -margin*2);

	glEnable(GL_SCISSOR_TEST);
	// attributes to Vertex Shad
	this->coord2d = program.attributeLocation("coord2d");
	program.enableAttributeArray(coord2d);
	program.setAttributeValue("coord2d", coord2d);
	program.setUniformValue("offsetX", GLfloat(plotSize/2));
	program.setUniformValue("scaleX", GLfloat(plotSize / 2));
	program.setUniformValue("scaleY", GLfloat(15.0));
	// attributes to Fragment Shad
	program.setUniformValueArray("f_color", PlotColor::RED, 1, 4);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

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

	// DRAWING AXIS and TICKS

	// CLEANING
	glDisableVertexAttribArray(coord2d);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void GLWidget::drawPoints2D(float pSize) {
	glPointSize(pSize);
	glDrawArrays(GL_POINTS, 0, 100);
}
