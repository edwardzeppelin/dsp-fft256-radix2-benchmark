#include "dsp-lecture.h"
#define MY_PI 3.14159265358979323846

void fft256_ref(cint16_t* dst, const cint16_t* src) {

	int N = 256;
	
	for (int k = 0; k < N; k++) {
		
		int64_t res_real = 0;
		int64_t res_imag = 0;
		
		for (int n = 0; n < N; n++) {
			
			double angle = 2 * MY_PI * k * n / N;
			
			int16_t cosine = (int16_t)(MAX_INT16 * cos(angle));
			int16_t sine = (int16_t)(MIN_INT16 * sin(angle));
			
			res_real += ((int64_t)src[n].real * cosine - (int64_t)src[n].imag * sine);
			res_imag += ((int64_t)src[n].real * sine + (int64_t)src[n].imag * cosine);
		}
		
		dst[k].real = (int16_t)(res_real >> 15);
		dst[k].imag = (int16_t)(res_imag >> 15);
	}
}