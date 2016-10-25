//
//  main.c
//  FFT
//
//  Created by 이동규 on 2016. 10. 25..
//  Copyright © 2016년 이동규. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "kiss_fft.h"
#include "kiss_fftr.h"
//#include "libsndfile-1.0.27/src/sndfile.h"

#define WIN 512

int main(void)
{
    char *music_file = "/Users/IronFactory/Desktop/bobby.mp3";
    FILE *in = fopen(music_file, "rb");
    char buf[WIN * 2];
    int nfft = WIN, i, fx;
    double intensity = 0;
    kiss_fft_cfg cfg;
    kiss_fft_cpx cx_in[WIN];
    kiss_fft_cpx cx_out[WIN];
    short *sh;
    
    cfg = kiss_fft_alloc(nfft, 0, 0, 0);
    if (!in) {
        printf("unable to open file: %s\n", music_file);
        perror("Error");
        return 1;
    }
    fx = 0;
    while (fread(buf, 1, WIN << 1, in))
    {
        for (i = 0;i<WIN;i++) {
            sh = (short *)(buf + i * 2);
            cx_in[i].r = (float) (((double)*sh) / 32768.0);
            cx_in[i].i = 0.0;
        }
        
        kiss_fft(cfg, cx_in, cx_out);
        //Display the value of a position
        int position;
        
        for (position = 0; position < WIN; position++) {
            // 강도 , M
            intensity = sqrt(pow(cx_out[position].r, 2) + pow(cx_out[position].i, 2));
            double phase = atan(cx_out[position].i / cx_out[position].r);
            int j;
            for (j = 0; j < (int) intensity; j++) {
                printf("*");
            }
            if (j > 0) {
                printf("\n");
            }
//            printf("inten = %9.4f\n", intensity);
        }
//        printf("phase = %9.4f\n", phase);
        
    }
    
    return 0;
}
