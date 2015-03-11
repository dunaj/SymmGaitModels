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
	glWidget = this->findChild<GLWidget*>("OpenGLWidget");

	markerNrLineEdit->setText("1");
	xRadioBtn->setChecked(true);
	yRadioBtn->setChecked(false);
	zRadioBtn->setChecked(false);
	connect(repaintBtn, SIGNAL(released()), this, SLOT(handleRepaintButton()));
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
