/*
 * FFT.cpp
 *
 *  Created on: 6 sty 2015
 *      Author: Adamek
 */

#include "FFT.h"

namespace Engine {

	FFTCol::FFTCol(const VecF & Xin) {
		int N = Xin.size();
		Xreal.resize(N, 0.0);
		Ximag.resize(N, 0.0);
		for (int k = 0; k< N; ++k) {

			for (int t = 0; t<N; ++t) {
				Xreal[k]+=  Xin[t]*cos(2*M_PI*t*k/N);
				Ximag[k]+= -Xin[t]*sin(2*M_PI*t*k/N);
			}
		}
	}

	void FFTCol::removeRedundantStripes() {
		try {
			if (Xreal.size() != Ximag.size()) {
				throw new double();
			}
			else if (Xreal.size() < LRMDS_ROW_NO || Ximag.size() < LRMDS_ROW_NO) {
				throw new int();
			}
			else {
				while (Xreal.size()!=LRMDS_ROW_NO) {
					Xreal.erase(Xreal.begin()+Xreal.size()/2);
					Ximag.erase(Ximag.begin()+Ximag.size()/2);
				}
			}
		}
		catch (double * d) {
			std::cout<<"Imaginary and Real part are not of equal size"<<std::endl;
		}
		catch (int *i) {
			std::cout<<"Size of FFT is less than planned LRMDS matrix duration"<<std::endl;
		}
	}

	void FFTCol::addLackingStripes() {
		try {
			if (Xreal.size() != Ximag.size()) {
				throw new double();
			}
			else if (Xreal.size() > LRMDS_ROW_NO || Ximag.size() > LRMDS_ROW_NO) {
				throw new int();
			}
			else {
				while (Xreal.size()!=LRMDS_ROW_NO) {
					Xreal.insert(Xreal.begin()+Xreal.size()/2, 0.0);
					Ximag.insert(Ximag.begin()+Ximag.size()/2, 0.0);
				}
			}
		}
		catch (double * d) {
			std::cout<<"Imaginary and Real part are not of equal size"<<std::endl;
		}
		catch (int *i) {
			std::cout<<"Size of FFT is less than planned LRMDS matrix duration"<<std::endl;
		}
	}

	std::ostream& operator<<(std::ostream& o, const FFTCol &col) {
		o.setf(std::ios::fixed, std::ios::floatfield);
		o.precision(7);
		o<<"Real\t\tImag"<<std::endl;
		for (unsigned i = 0; i<col.getReal().size(); ++i) {
			o<<col.getReal()[i]<<"\t"<<col.getImag()[i];
			o<<std::endl;
		}
		return o;
	}

	bool operator==(FFTCol &fft, FFTCol &compFFT) {
		if ( fft.size() != compFFT.size() )
			return false;

		for ( unsigned ind = 0; ind < fft.size(); ++ind ) {
			if (std::abs(fft.getReal()[ind] - compFFT.getReal()[ind])
					> FFT_TOLERANCE) {
				return false;
			}
			if (std::abs(fft.getImag()[ind] - compFFT.getImag()[ind])
					> FFT_TOLERANCE) {
				return false;
			}
		}

		return true;
	}

	bool FFTCol::equalsVec(const VecF & real, const VecF& imag) {
		if ( size() != real.size() || size() != imag.size() )
			return false;

		for (unsigned ind = 0; ind < this->size(); ++ind) {
			if (std::abs(this->getReal()[ind] - real[ind]) > FFT_TOLERANCE
					|| std::abs(this->getImag()[ind] - imag[ind]) > FFT_TOLERANCE )
				return false;
		}
		return true;
	}

	// //////////////////////////////////////////////////////////////////////////
	// FFT MATRIX
	FFTMat::FFTMat(const Engine::Matrix & m) {
		columns.resize(LRMDS_COL_NO);
		for (int col = 0; col < LRMDS_COL_NO; ++col) {
			columns[col]=FFTCol(m.getColumn(col));
		}
	}

	void FFTMat::removeRedundantStripes() {
		for (unsigned col = 0; col < columns.size(); ++col ) {
			columns[col].removeRedundantStripes();
		}
	}

	void FFTMat::addLackingStripes() {
		for (unsigned col = 0; col < columns.size(); ++col ) {
			columns[col].removeRedundantStripes();
		}
	}
} /* namespace Engine */
