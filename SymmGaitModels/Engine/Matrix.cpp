/*
 * Matrix.cpp
 *
 *  Created on: 22-10-2014
 *      Author: Adamek
 */

#include "Matrix.h"
#include <fstream>
namespace Engine {
Matrix::Matrix(const char * fileN, int nC, int nV)
{
	this->nCol=nC;
	this->nVer = nV;
	std::fstream file;
	file.open(fileN, std::ios::in);
	if (file.is_open()) {
		this->m.resize(nV);
		for (int i = 0; i<nV; ++i) {
			this->m[i].resize(nC);
			for (int j = 0; j < nC; ++j ) {
				file>>this->m[i].at(j);
			}
		}
		file.close();
	}
	else {
		std::cout<<"Cannot open file "<<fileN<<"!!!"<<std::endl;
	}
}

std::ostream& operator<<(std::ostream& o, const Matrix &mat)
{
	o.setf(std::ios::scientific, std::ios::floatfield);
	o.precision(7);
	for (int i = 0; i<mat.nVer; ++i) {
		for (int j = 0; j < mat.nCol; ++j ) {
			o<<mat(i,j)<<"\t";
		}
		o<<std::endl;
	}
	return o;
}

} //namespace Engine
