#include "symmgaitmodels.h"

SymmGaitModels::SymmGaitModels(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	xRadioBtn = this->findChild<QRadioButton*>("XRadioButton");
	yRadioBtn = this->findChild<QRadioButton*>("YRadioButton");
	zRadioBtn = this->findChild<QRadioButton*>("ZRadioButton");
	markerNrLineEdit = this->findChild<QLineEdit*>("MarkerNrLineEdit");
	repaintBtn = this->findChild<QPushButton*>("RepaintButton");
	loadMatrixBtn = this->findChild<QPushButton*>("LoadMatrixButton");
	loadedMatrixNameLabel = this->findChild <QLabel*>("LoadedMatrixNameLabel");
	glWidget = this->findChild<GLWidget*>("OpenGLWidget");

	markerNrLineEdit->setText("1");
	xRadioBtn->setChecked(true);
	yRadioBtn->setChecked(false);
	zRadioBtn->setChecked(false);
	connect(repaintBtn, SIGNAL(released()), this, SLOT(handleRepaintButton()));
	connect(loadMatrixBtn, SIGNAL(released()), this, SLOT(handleLoadMatrixButton()));
}

SymmGaitModels::~SymmGaitModels() {

}

void SymmGaitModels::handleRepaintButton() { // TODO zrobic to idioto odporne
	int markerNr = (markerNrLineEdit->text()).toInt();
	if (xRadioBtn->isChecked()) {
		glWidget->setPaintedColumn(markerNr, 1);
	}
	if (yRadioBtn->isChecked()) {
		glWidget->setPaintedColumn(markerNr, 2);
	}
	if (zRadioBtn->isChecked()) {
		glWidget->setPaintedColumn(markerNr, 3);
	}
	glWidget->repaint();
}

void SymmGaitModels::handleLoadMatrixButton() {
	QString fileName = QFileDialog::getOpenFileName(this, tr("Load Matrix"), ".", tr("Text files (*.txt)"));
	std::string tempStr = fileName.toLocal8Bit().constData();
	const char * fileNameCharArr = tempStr.c_str();
	glWidget->readMatrixFromFile(fileNameCharArr);
	loadedMatrixNameLabel->setText(parseFileName(fileName));
	glWidget->repaint();
}

QString SymmGaitModels::parseFileName(const QString & fileNameWithPath) const {
	QString fileName = "";
	for (int i = fileNameWithPath.size() - 1; i >= 0; --i) {
		if (fileNameWithPath[i] == '/')
			break;
		fileName.prepend(fileNameWithPath[i]);
	}
	return fileName;
}
