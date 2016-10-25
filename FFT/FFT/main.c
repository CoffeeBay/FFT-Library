//
//  main.c
//  FFT
//
//  Created by 이동규 on 2016. 10. 25..
//  Copyright © 2016년 이동규. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "fftw-3.3.5/api/fftw3.h"

#define WIN 32

int main(int argc, const char * argv[]) {
    int inputSize = 1024;
    int outputSize = ((inputSize >> 1) + 1);
    
    double *inputBuffer = (double *) (fftw_malloc(inputSize * sizeof(double)));
    fftw_complex *outputBuffer = (fftw_complex *) (fftw_malloc(outputSize * sizeof(fftw_complex)));
    
    int flags = FFTW_ESTIMATE;
    fftw_plan plan = fftw_plan_dft_r2c_1d(inputSize, inputBuffer, outputBuffer, flags);
    fftw_execute(plan);
    
    printf("%d\n", sizeof(outputBuffer) / sizeof(outputBuffer[0]));
    
    fftw_free(inputBuffer);
    fftw_free(outputBuffer);
    fftw_destroy_plan(plan);
    return 0;
}
