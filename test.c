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
   fread(header, sizeof(char),54,fp);
   for(int i =0;i<54;i++){
      printf("%c \n",header[i]);
   }
   // int i=60;
   // while(i) {
   //    c = fgetc(fp);
   //    if( feof(fp) ) { 
   //       break ;
   //    }
   //     int unicode= (int)c;
   //    printf("%d    %c  \n ", unicode,c);
   //    --i;
   // }

   char in[BLOCK_SIZE];
   char buffer[BLOCK_SIZE];
   int numberOfBlocks=0;
   while(numberOfBlocks>=0){
      
      long amount_read = fread(in, sizeof(char),BLOCK_SIZE,fp);
      if(amount_read<BLOCK_SIZE){
         memcpy(buffer,in,amount_read);
         for(int i=amount_read;i<BLOCK_SIZE+1;i++){
            buffer[i]=0;
         }
         break;
         memcpy(buffer,in,BLOCK_SIZE);
      }
      numberOfBlocks++;


   }




   void myEncryptAlgo(char *block[BLOCK_SIZE],int KEY,){
      
   }
   
   
   fclose(fp);
   
   return(0);
}