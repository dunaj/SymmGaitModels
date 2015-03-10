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
typedef std::vector<float> Column;

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
	int nRow;

public:
	/**
	 * Default Ctor
	 */
	Matrix() {};
	/**
	 * Konstruktor tworzacy macierz na podstawie pliku txt
	 * ktory przekazemy
	 */
	Matrix(const char * nazwa_pliku, int nC, int nR);

	/**
	 * overloaded operator()
	 * gets an element from the column and row
	 */
	const float & operator()(int col, int row) const {
		return m[col].at(row);
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
