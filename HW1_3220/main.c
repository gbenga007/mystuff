/* 
 * File:   main.c
 * Author: Gbenga Omotara
 *
 * Created on February 24, 2016, 8:34 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(int argc, char** argv) {
      
    if (argc < 4){
        printf("\nNot enough command line arguments!");
        return 0;
    }
    
    const char* inFile = argv[1];
    const char* outFile = argv[2];
    int threshold = atoi(argv[3]);
    
    char imageType[2] = {0};
    int x,y, max;
    int rows, col;
    int i = 0;
    int num = 0;
    
    // Variables for computation
    int magnitude = 0;
    int magnitude2 = 0;
    int sumx = 0;
    int sumy = 0;
    float gradient = 0;
    int num2 = 0;
    int num3 =0;
    int num4 = 0;
    
    FILE* input = fopen(inFile, "r");
    FILE* output = fopen(outFile, "w");
    
    if(input == NULL){
        perror("\nFile is invalid");
        return(-1);
    }
    
    fscanf(input,"%s",imageType);
    fscanf(input,"%d %d",&x,&y);      
    fscanf(input,"%d",&max); 
    

   /*Image array Variables*/ 
    int* kernelx = (int*) malloc(9*(sizeof(int)));
    int* kernely = (int*) malloc(9*(sizeof(int)));
    int* pixel = (int*) malloc((x*y)*(sizeof(int)));
    int kernelx_array[9] = {-1,0,1,-2,0,2,-1,0,1}; // holds matrix values for X kernel
    int kernely_array[9] = {-1,-2,-1,0,0,0,1,2,1}; // holds matrix values for Y kernel
    
    /*File opening*/
   
  
    /*Loading the image array into pointers for manipulation*/
    for(i=0; i<9; i++){
        num = kernelx_array[i];
        *(kernelx+i)= kernelx_array[i];
    }
    for(i=0; i<9; i++){
        *(kernely+i)= kernely_array[i];
    } 
    
/*
        fscanf(input,"%d %d",&x,&y);      
        fscanf(input,"%d",&max);
        
*/
        fprintf(output,"%s\n %d %d\n %d\n",imageType,x,y,max);
/*
        fprintf(output,"%d %d\n",x,y);
        fprintf(output,"%d\n", max);
*/

     for(rows=0;rows<x;rows++)
        {
            for(col=0;col<y;col++)
            {
                fscanf(input,"%d ",&pixel[col+rows*y]);
            }
        }
        
     for(rows=1;rows<y;rows++)
        {
            for(col=1;col<x;col++)
            {

/*
                num =0;
                --rows; //  takes us to access values at upper row 
                
                num = *(pixel+col-1);// stores value in top left of the 3x3 matrix
                num2 = *(pixel+col+1);// stores value in top left of 3x3 matrix
                
                ++rows;// brings us down by 1
                ++rows;// brings us to the bottom row of the 3x3 matrix
                
                num3 = *(pixel+col-1);// stores value in the bottom left of the 3x3 matrix
                num4 = *(pixel+col+1);// stores value in the bottom right of the 3x3 matrix
                
                --rows; //  returns to the row we want
 
*/

               //pixel[col+rows*y];
               // sumx = *(pixel+rows-1) * (*(kernelx+1)) + *(pixel+rows+1) * (*(kernelx+7)) + *(pixel+col-1) * (*(kernelx+3)) + *(pixel+col+1) * (*(kernelx+5)) + num *(*(kernelx+0))+ num2 * (*(kernelx+2))+ num3* (*(kernelx+6))+ num4 * (*(kernelx+8));
               // sumy = *(pixel+rows-1) * (*(kernely+1)) + *(pixel+rows+1) * (*(kernely+7)) + *(pixel+col-1) * (*(kernely+3)) + *(pixel+col+1) * (*(kernely+5)) + num *(*(kernely+0))+ num2 * (*(kernely+2))+ num3* (*(kernely+6))+ num4 * (*(kernely+8)); ;
               sumx = *(pixel+(rows-1)+(col-1)*x) * (*(kernelx+0)) + *(pixel+(rows-1)+(col)*x) * (*(kernelx+1)) + *(pixel+(rows-1)+(col+1)*x) * (*(kernelx+2)) + *(pixel+(rows)+(col-1)*x) * (*(kernelx+3)) + 0 + *(pixel+(rows)+(col+1)*x) * (*(kernelx+5)) + *(pixel+(rows+1)+(col-1)*x) * (*(kernelx+6))+ *(pixel+(rows+1)+(col)*x) * (*(kernelx+7)) + *(pixel+(rows+1)+(col+1)*x) * (*(kernelx+8));
               sumy = *(pixel+(rows-1)+(col-1)*x) * (*(kernely+0)) + *(pixel+(rows-1)+(col)*x) * (*(kernely+1)) + *(pixel+(rows-1)+(col+1)*x) * (*(kernely+2)) + *(pixel+(rows)+(col-1)*x) * (*(kernely+3)) + 0 + *(pixel+(rows)+(col+1)*x) * (*(kernely+5)) + *(pixel+(rows+1)+(col-1)*x) * (*(kernely+6))+ *(pixel+(rows+1)+(col)*x) * (*(kernely+7)) + *(pixel+(rows+1)+(col+1)*x) * (*(kernely+8));
   
                magnitude = pow(sumx,2);
                magnitude2 = pow(sumy,2);
                gradient = (float) sqrt(sumx +sumy);
                fprintf(output,"%d",gradient);
              
            }
        }
        
        for(rows = 0; rows<y;rows++)
          {
            for(col = 0; col <x; col++){
            fprintf(output,"%d ",(*(pixel+rows+col*x)));
         }
        }
    
    free(kernelx);    
    free(kernely);
    fclose(input);
    fclose(output);
    return (EXIT_SUCCESS);
}




