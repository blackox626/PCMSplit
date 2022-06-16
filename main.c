#include <stdio.h>
#include <stdlib.h>

/**
 * Split Left and Right channel of 32LE PCM file.
 * @param url  Location of PCM file.
 *
 */
int simplest_pcm32le_split(char *url){
    FILE *fp=fopen(url,"rb+");
    FILE *fp1=fopen("/Users/blackox626/CLionProjects/PCMSplit/resource/output_l.pcm","wb+");
    FILE *fp2=fopen("/Users/blackox626/CLionProjects/PCMSplit/resource/output_r.pcm","wb+");

    unsigned char *sample=(unsigned char *)malloc(8);

    while(!feof(fp)){
        fread(sample,1,8,fp);
        //L
        fwrite(sample,1,4,fp1);
        //R
        fwrite(sample+4,1,4,fp2);
    }

    free(sample);
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    return 0;
}

/**
 * Halve volume of Left channel of 16LE PCM file
 * @param url  Location of PCM file.
 */
int simplest_pcm32le_halfvolumeleft(char *url){
    FILE *fp=fopen(url,"rb+");
    FILE *fp1=fopen("/Users/blackox626/CLionProjects/PCMSplit/resource/output_halfleft.pcm","wb+");

    int cnt=0;

    unsigned char *sample=(unsigned char *)malloc(8);

    while(!feof(fp)){
        short *samplenum=NULL;
        fread(sample,1,8,fp);

        samplenum=(short *)sample;
        *samplenum=*samplenum/2;
        //L
        fwrite(sample,1,4,fp1);
        //R
        fwrite(sample+4,1,4,fp1);

        cnt++;
    }
    printf("Sample Cnt:%d\n",cnt);

    free(sample);
    fclose(fp);
    fclose(fp1);
    return 0;
}

int main() {
    //printf("Hello, World!\n");

    char *pcmPath = "/Users/blackox626/CLionProjects/PCMSplit/resource/audio.pcm";
//    simplest_pcm32le_split(pcmPath);
    simplest_pcm32le_halfvolumeleft(pcmPath);
    return 0;
}
