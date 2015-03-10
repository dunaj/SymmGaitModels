#include "symmgaitmodels.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SymmGaitModels w;

	w.show();
	return a.exec();
}
