/*
 * engConsts.h
 *
 *  Created on: 7 sty 2015
 *      Author: Adamek
 */

#ifndef ENGINE_CONSTS_H_
#define ENGINE_CONSTS_H_

namespace Engine {
#ifndef M_PI
	const double M_PI = 3.1415926535897932384626434;
#endif
	/**
	* tolerance of FFT transform elements equality
	* as the benchmark for the FFT implementation
	* is MatLab FFT implementation, which is more accurate
	*/
	const static double FFT_TOLERANCE = 0.000001;
	//Consants for Mean Double Step matrices
	const int MDS_COL_NO = 79;
	const int MDS_ROW_NO = 100; // mds duration

	//Constants for R/L Mean Double Step Matrices
	const int LRMDS_COL_NO = 78;
	const int LRMDS_ROW_NO = 100; // rlmds duration
}

#endif /* ENGINE_CONSTS_H_ */
