#ifndef DSP_LECTURE_H
#define DSP_LECTURE_H

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <arm_acle.h>
#include <arm_neon.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

#define N_MAX 65535
#define MAX_INT16 32767
#define MIN_INT16 (-32768)
#defien FFT_SIZE 256

typedef struct { int16_t real,imag; } cint16_t;
typedef struct { int32_t real,imag; } cint32_t;

void fft256_fast(cint16_t* dst, const cint16_t* src);
void fft256_ref(cint16_t* dst, const cint16_t* src);

#endif /* DSP_LECTURE_H */
