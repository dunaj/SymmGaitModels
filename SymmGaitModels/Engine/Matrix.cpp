/*
 * Matrix.cpp
 *
 *  Created on: 22-10-2014
 *      Author: Adamek
 */

#include "Matrix.h"
#include <fstream>
namespace Engine {
Matrix::Matrix(const char * fileName, int nC, int nR)
{
	this->nCol=nC;
	this->nRow = nR;
	std::fstream file;
	file.open(fileName, std::ios::in);
	if (file.is_open()) {
		this->m.resize(nC);
		for (int col = 0; col < nC; ++col)
			m[col].resize(nR);
		for (int row = 0; row < nR; ++row) {
			for (int col = 0; col<nC; ++col) {
				file>>this->m[col].at(row);
			}
		}
		file.close();
	}
	else {
		std::cout<<"Cannot open file "<<fileName<<"!!!"<<std::endl;
	}
}

std::ostream& operator<<(std::ostream& o, const Matrix &mat)
{
	o.setf(std::ios::scientific, std::ios::floatfield);
	o.precision(7);
	for (int i = 0; i<mat.nRow; ++i) {
		for (int j = 0; j < mat.nCol; ++j ) {
			o<<mat(j,i)<<"\t";
		}
		o<<std::endl;
	}
	return o;
}

} //namespace Engine
