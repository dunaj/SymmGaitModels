#ifndef SYMMGAITMODELS_H
#define SYMMGAITMODELS_H

#include <QtWidgets/QWidget>
#include <QtWidgets/qfiledialog.h>
#include "ui_symmgaitmodels.h"
#include <string>

class SymmGaitModels : public QWidget
{
	Q_OBJECT

public:
	SymmGaitModels(QWidget *parent = 0);
	~SymmGaitModels();

private slots:
	void handleRepaintButton();
	void handleLoadMatrixButton();

private:
	Ui::SymmGaitModelsClass ui;
	QRadioButton* xRadioBtn;
	QRadioButton* yRadioBtn;
	QRadioButton* zRadioBtn;
	QLineEdit* markerNrLineEdit;
	QPushButton* repaintBtn;
	QPushButton* loadMatrixBtn;
	QLabel * loadedMatrixNameLabel;
	GLWidget* glWidget;

	/**
	 * method extracting only file name from Qstring containing path/filename
	 * taking only characters from the last '/' to the end of string
	 *
	 * @param fileNameWithPath
	 * @return plane fileName
	 */
	QString parseFileName(const QString &fileNameWithPath) const;
};

#endif // SYMMGAITMODELS_H
