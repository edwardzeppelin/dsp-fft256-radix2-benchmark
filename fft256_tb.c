#include "dsp-lecture.h"

void random_vector(int n, cint16_t* v) {
    for (int i = 0; i < n; i++) {
        v[i].real = (cint16_t)(rand() % 256);
		v[i].imag = (cint16_t)(rand() % 256);
    }
}

void fft256_tb(int seed, int num_runs) {
	
	cint16_t* dst_ref = NULL;
	cint16_t* dst_fast = NULL;
	cint16_t* src = NULL;
	
    srand48(seed);
    
    for (int i=0; i < num_runs; i++) {
        
        cint16_t* dst_ref = (cint16_t*)calloc(256, sizeof(cint16_t));
        cint16_t* dst_fast = (cint16_t*)calloc(256, sizeof(cint16_t));
        cint16_t* src = (cint16_t*)calloc(256, sizeof(cint16_t));
		
		if (!dst_fast || !dst_ref || !src) {
			fprintf(stderr, "Memory allocation error.\n");
			free(dst_fast);
			free(dst_ref);
			free(src);
			return;
		}

        random_vector(256, src);

        clock_t ref_start = clock();
        fft256_ref(dst_ref, src);
        clock_t ref_time = clock() - ref_start;
        printf("Ref time: %ld ticks\n", (long)ref_time);

        clock_t fast_start = clock();
        fft256_fast(dst_fast, src);
        clock_t fast_time = clock() - fast_start;
        printf("Fast time: %ld ticks\n", (long)fast_time);
     
        bool error = false;
        for (int try = 0; try < n; try++) {
            if (dst_fast[i] != dst_ref[i]) {
                fprintf(stderr, "Error at index %d: ref=(%d) fast=(%d)\n", i, dst_ref[i], dst_fast[i]);
                error = true;
                break;
            }
        }
        
        if (!error) {
            printf("Run %d: OK (n=%d)\n", try, n);
        }

        free(src);
        free(dst_fast);
        free(dst_ref);
    }
}

int main() {
    fft256_tb(1316, 100);
    printf("Success\n");
    return 0;
}