#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wave.h"

int main(int argc,char*argv[]){
    MONO_PCM pcmForWrite[8], pcmForRead;
    //音符
    int sound_nate;
    int i;
    //振幅
    double amplitude;
    //周波数
    double frequency[8]={261.626,293.665,329.628,349.228,391.995,440.0,493.883,523.251};
    int oto;
    int length_oto;
    char name[256];
    // pcmForWrite[8].fs = 8000;
    // pcmForWrite[8].bits = 16;
    // pcmForWrite[8].length = 8000*1;
    // pcmForWrite[8].s = calloc(pcmForWrite.length, sizeof(double));
       length_oto=atoi(argv[1]);
       printf("%d",length_oto);
    amplitude = 0.25;
    // frequency[12]={262.0,277.0,294.0,311.0,330.0,349.0,370.0,392.0,415.0,440.0,466.0,494.0};
    for(oto=0;oto<8;oto++){
        pcmForWrite[oto].fs = 8000;
        pcmForWrite[oto].bits = 16;
        pcmForWrite[oto].length =length_oto;
        pcmForWrite[oto].s = calloc(pcmForWrite[oto].length, sizeof(double));

        for(i = 0; i < pcmForWrite[oto].length; i++){
            // A sin(2πft0/fs) + A/2 sine(2πft1/fs) ・・・
            pcmForWrite[oto].s[i] = amplitude * sin((2.0 * M_PI * frequency [oto]* i) / pcmForWrite[oto].fs);
        }
        sprintf(name,"oto%d.wav",oto);
        monoWaveWrite(&pcmForWrite[oto], name);
        free(pcmForWrite[oto].s);

        // monoWaveRead(&pcmForRead, "testWave.wav");
        // for(i = 0; i < pcmForRead.length; i++){
        //     printf("%d:%lf\n", i, pcmForRead.s[i]);
        // }
        // free(pcmForRead.s);
    }
    return 0;
}
