#ifndef GLWIDGET__H_
#define GLWIDGET__H_

#include <qopenglfunctions.h>
#include <qopenglwidget.h>
#include <qopenglshaderprogram.h>
#include <qopenglbuffer.h>
#include <iostream>
#include <fstream>

#include "Engine\Matrix.h"
#include "Engine\Consts.h"
#include "PlotColor.h"

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
	Q_OBJECT
public:
	GLWidget(QWidget *parent);
	~GLWidget();

	/**
	 * sets the column which user wants to be painted
	 * basing on data from Line Edit and Radio Buttons
	 * from GUI
	 * @param markerNr - marker number (from 1 to 26)
	 * @param coord - 1=x, 2=y, 3=z
	 */
	void setPaintedColumn(int markerNr, int coord);
protected:
	struct Point;

	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
	//void mousePressEvent(QMouseEvent * event);
	//void mouseMoveEvent(QMouseEvent * event);
private:
	QOpenGLShaderProgram program;
	QOpenGLShader *vertexShad;
	QOpenGLShader *fragmentShad;
	QOpenGLBuffer *vertexBuff;

	/* 2D plot members */
	Point * plot;
	int plotSize;
	GLint coord2d;
	GLuint positionBufferObject;
	GLuint vbo;
	GLint plotColor;
	float scaleY;
	float offsetY;
	int paintedColumn;

	// MDS MAtrix
	Engine::Matrix *mds;

	// OTHER
	GLfloat rotatex;
	GLfloat rotatey;
	QPoint mousePos;

	/**
	 * Method painting 2D plot
	 */
	void paintPlot2D();

	/**
	 * Method drawing points on 2D plot
	 */
	void drawPoints2D(float pSize = 4.0);

	/**
	 * Method drawing black zero rule
	 */
	void drawZeroRule2D();
	/**
	 * Method used for preparing data to 2D plot
	 */
	void prepareData2D();

	/**
	 * Writing matrix to file
	 */
	void writeMatToFile(const char * fileName);

	/**
	 * Finding a proper scale and offset to make plot visible
	 */
	void findScaleAndOffset();

	// CONSTANTS
	const char *vertexShadSrc = // Vertex shader src
		"uniform sampler2D texture; "
		"attribute vec4 coord2d; \n"
		"uniform float offsetX; \n"
		"uniform float scaleX; \n"
		"uniform float scaleY; \n"
		"uniform float offsetY; \n"
		"void main() \n"
		"{\n"
		" float x = (coord2d[0]-offsetX)/scaleX; \n "
		" float y = (coord2d[1]-offsetY) / scaleY; //texture2D(texture, vec2(x, coord2d[1])).r; \n "
		" gl_Position = vec4(x, y, 0.0, 1.0); \n"
		"}\n";
	const char *fragmentShadSrc = // Fragment Shader src
		"uniform vec4 f_color; "
		"void main(void) {        "
		"gl_FragColor = f_color; " 
		"}";
};

#endif // GLWIDGET_H__