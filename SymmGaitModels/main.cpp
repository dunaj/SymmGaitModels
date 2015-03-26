#include "symmgaitmodels.h"
#include <QtWidgets/QApplication>
#include <iostream>

#include "main.h"

/*
 @TODO operacje na sygna³ach 
 @TODO dodawanie kolejnych sygna³ów do wykresu
 @TODO Przetestowaæ FFT
 @TODO Usuwanie pr¹¿ków FFT - Uproszczenie chodu
 @TODO kryterium podzia³u kroku
 @TODO konkatenacja
 @todo w dpmie musi byæ konkatenacja zeby siê zaczyna³y w tym samym momencie
 @TODO podzia³ na LŒK i PŒK
 @todo Przed³u¿enia funkcyjne
 @todo animacja 3D
 @todo Formu³a liczenia asymetrii
*/

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SymmGaitModels w;
	w.show();
	return a.exec();
}
