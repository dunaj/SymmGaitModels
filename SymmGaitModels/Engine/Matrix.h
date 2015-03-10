/*
 * Matrix.h
 *
 *  Created on: 22-10-2014
 *      Author: Adamek
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
#include <iostream>
#include <iomanip>
namespace Engine {
/**
 * Kolumna jest reprezentowana przez wektor liczb zmiennoprzecinkowych
 */
typedef std::vector<double> Column;

/**
 * Klasa reprezentujaca macierz
 */
class Matrix
{
private:
	///dane
	std::vector<Column> m;
	///liczba kolumn
	int nCol;
	///liczba wierszy
	int nVer;

public:
	/**
	 * Konstruktor tworzacy macierz na podstawie pliku txt
	 * ktory przekazemy
	 */
	Matrix(const char * nazwa_pliku, int nC, int nV);

	/**
	 * przeci¹¿ony operator()
	 *
	 * zapewnia dotarcie do danego elementu macierzy
	 */
	const double & operator()(int kol, int wiersz) const
	{
		return m[kol].at(wiersz);
	}

	Column getColumn(int index) const {
		return m[index];
	}
	/**
	 * Przeciazony operator do wypisywania zawartosci macierzy
	 */
	friend std::ostream & operator<<(std::ostream&, const Matrix &m);

};
} // namespace Engine

#endif /* MATRIX_H_ */
