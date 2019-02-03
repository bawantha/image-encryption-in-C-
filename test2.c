#include <stdio.h>
#include <malloc.h>
#include <string.h>

// CODED BY R.B.M. Rajapaksha
// 160509B
//



// Define constants

#define INPUT_FILE_NAME "watercolor.ppm"
#define OUTPUT_FILE_NAME_ECB "enc_watercolor_ecb.ppm"
#define OUTPUT_FILE_NAME_CBC "enc_watercolor_CBC.ppm"
#define BLOCK_SIZE 24
const int  KEY[]={11,
10,
17,
 3,
 9,
23,
18,
 7,
15,
 1,
 0,
21,
19,
16,
12,
 2,
 8,
 6,
 5,
20,
22,
13,
 4,
14};



int main(){
    printf("%d",sizeof(KEY)/sizeof(int));
    char in[BLOCK_SIZE];
    char ciper[BLOCK_SIZE];
    char header[54];
    FILE *fp,*fo;
    fp=fopen("watercolor.ppm","rb");
    fo=fopen("watercolor_ECB.ppm","wb");
    

    // header value is taken
    int header_read=fread(header,sizeof(char),54,fp);

    // header value is written to output
    fwrite(header,sizeof(char),54,fo);

 

    
    while(1){
        int read= fread(in,sizeof(char),BLOCK_SIZE,fp);
        if(read<BLOCK_SIZE){
            for(int i=read;i<BLOCK_SIZE;i++){
                in[i]=0;
            }
            break;
        }
        for(int i=0;i<BLOCK_SIZE;++i){
        int temp=in[i];
        in[i]=in[KEY[i]];
        in[KEY[i]]=temp;
        fwrite(in,sizeof(char),BLOCK_SIZE,fo);
    }
    }
}
    


    
   


