/*
 * FFT.h
 *
 *  Created on: 6 sty 2015
 *      Author: Adamek
 */

#ifndef ENGINE_FFT_H_
#define ENGINE_FFT_H_

#include <vector>
#include <cmath>
#include <ostream>
#include "Consts.h"
#include <iostream>
#include "Matrix.h"

namespace Engine {

typedef std::vector<double> VecD;
/**
 * Class which represents a Column of Fourier Transform
 * Has tables of Real and Imaginary part
 */
class FFTCol {
private:
	VecD Xreal;
	VecD Ximag;

public:
	FFTCol() {

	}
	/**
	 * Constructor which input is column of raw, MDS or R/L-MDS matrix
	 */
	FFTCol(const VecD & Xin);

	VecD getReal() const {
		return Xreal;
	}
	VecD getImag() const {
		return Ximag;
	}
	void removeRedundantStripes();
	void addLackingStripes();
	unsigned size() {
		return Xreal.size();
	}

	/**
	 * printing the FFT
	 */
	friend std::ostream & operator<<(std::ostream&, const FFTCol &m);

	/**
	 * operator to check if FFTCol is equal to other FFTCol
	 * containing Fourier Transform.
	 * Equality is fitting in a presumed tolerance (const parameter)
	 */
	friend bool operator==(FFTCol &fft, FFTCol &compFFT);

	/**
	 * function checking if the FFTCol is equal to preasumed
	 * std vectors with real and imag part
	 */
	bool equalsVec (const VecD & real, const VecD &imag);
};

class FFTMat {
private:
	std::vector<FFTCol> columns;
	FFTMat();
public:
	FFTMat(const Engine::Matrix&);
	void removeRedundantStripes();
	void addLackingStripes();

};

} /* namespace Engine */

#endif /* ENGINE_FFT_H_ */
