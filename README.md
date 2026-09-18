# 256-Point Fixed-Point Complex FFT (Q15)

Performance benchmark and verification suite for a 256-point complex **Fast Fourier Transform (FFT)** implemented in 16-bit Q15 fixed-point arithmetic using the **Cooley-Tukey Radix-2 algorithm**.

## Key Features
* **Radix-2 Cooley-Tukey Architecture**: Computes 256-point complex FFT across 8 radix-2 stages ($2^8 = 256$).
* **Bit-Reversal Permutation**: Fast input reordering using a 256-element precomputed lookup table (`bitrev_table`).
* **Q15 Fixed-Point Arithmetic**: Utilizes precalculated Q15 sine/cosine twiddle factor tables (`fft256_twiddle_real`, `fft256_twiddle_imag`) and 15-bit scaling (`>> 15`) to prevent overflow.
* **Verification & Benchmarking Framework**: Measures execution ticks using `clock()` and verifies fixed-point fast FFT outputs against a full-precision reference DFT implementation (`fft256_ref`).

## Project Structure
* `fft256_fast.c` — Optimized 256-point Radix-2 FFT with bit-reversal table and Q15 butterfly operations.
* `fft256_ref.c` — Reference Discrete Fourier Transform (DFT) implementation using standard trigonometric functions.
* `fft256_tb.c` — Automated benchmark testbench with randomized complex vector generation and performance timer.
* `dsp-lecture.h` — System definitions, `cint16_t` structure, and function prototypes.

## Build & Run

```bash
gcc -O2 fft256_tb.c fft256_fast.c fft256_ref.c -lm -o fft256_test
./fft256_test
```
