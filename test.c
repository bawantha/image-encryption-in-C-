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



int main(){
   FILE *fp;
   int c;
   char header[54];
  
   fp = fopen("watercolor.ppm","rb");
   fread(header, sizeof(char),53,fp);
   char in[BLOCK_SIZE];
   char buffer[BLOCK_SIZE];
   int numberOfBlocks=10;


   long amount_read=fread(in,sizeof(char),BLOCK_SIZE,fp);
   printf("%s",in);
 







   while(numberOfBlocks>=0){
      
      long amount_read = fread(in, sizeof(char),BLOCK_SIZE,fp);
      if(amount_read<BLOCK_SIZE){
         memcpy(buffer,in,amount_read);
         
         break;
         memcpy(buffer,in,BLOCK_SIZE);
      }
      numberOfBlocks--;
   
   fclose(fp);
   
   return(0);
   }
}