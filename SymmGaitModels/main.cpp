#include "symmgaitmodels.h"
#include <QtWidgets/QApplication>
#include <iostream>

#include "main.h"

/*
 @TODO operacje na sygna�ach 
 @TODO dodawanie kolejnych sygna��w do wykresu
 @TODO Przetestowa� FFT
 @TODO Usuwanie pr��k�w FFT - Uproszczenie chodu
 @TODO kryterium podzia�u kroku
 @TODO konkatenacja
 @todo w dpmie musi by� konkatenacja zeby si� zaczyna�y w tym samym momencie
 @TODO podzia� na L�K i P�K
 @todo Przed�u�enia funkcyjne
 @todo animacja 3D
 @todo Formu�a liczenia asymetrii
*/

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SymmGaitModels w;
	w.show();
	return a.exec();
}
