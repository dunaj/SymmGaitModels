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

private:
	Ui::SymmGaitModelsClass ui;
};

#endif // SYMMGAITMODELS_H
