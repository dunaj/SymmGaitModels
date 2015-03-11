#ifndef SYMMGAITMODELS_H
#define SYMMGAITMODELS_H

#include <QtWidgets/QWidget>
#include "ui_symmgaitmodels.h"

class SymmGaitModels : public QWidget
{
	Q_OBJECT

public:
	SymmGaitModels(QWidget *parent = 0);
	~SymmGaitModels();

private slots:
	void handleRepaintButton();

private:
	Ui::SymmGaitModelsClass ui;
	QRadioButton* xRadioBtn;
	QRadioButton* yRadioBtn;
	QRadioButton* zRadioBtn;
	QLineEdit* markerNrLineEdit;
	QPushButton* repaintBtn;
	GLWidget* glWidget;
};

#endif // SYMMGAITMODELS_H
