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

int main() {
    //printf("Hello, World!\n");

    char *pcmPath = "/Users/blackox626/CLionProjects/PCMSplit/resource/audio.pcm";
    simplest_pcm32le_split(pcmPath);

    return 0;
}
