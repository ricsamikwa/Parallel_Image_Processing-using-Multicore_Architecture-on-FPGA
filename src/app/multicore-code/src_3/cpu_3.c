#include "system.h"
#include <stdio.h>
#include "io.h"

//#define DEBUG

#define imageHorizontal 360
#define imageVertical 260

unsigned int* imageAddress = (unsigned int*) (SDRAM_BASE + 4 +(3*imageHorizontal*imageVertical*3));
unsigned char grayed[imageHorizontal*imageVertical/4];

//synchronisation flags
unsigned int* cpus_wait = (unsigned int*) (SDRAM_BASE + 30000000);
unsigned int* cpu_3_wait = (unsigned int*) (SDRAM_BASE + 30000012);

unsigned int* rowNumber = (unsigned int*) (SDRAM_BASE + 30000016);
unsigned int numberOfRows;

void grayscale(){ //a function to get the image from a header file, convert it to a matrix and grayscale it
   //PERF_BEGIN(P_COUNTER_BASE, 2);
	int columnSize = imageHorizontal*3; //size of the column for the rgb matrix
	int rowSize = imageVertical;
	int i;
  int j;
  unsigned int k = 0;
  float R, G, B;
  float Y,U,V,UV,R1,R2,R3,G1,G2,G3,B1,B2,B3,R4,G4,B4;
	unsigned char I1;
  for(i = 0; i < numberOfRows; i++) { //cycle through rows
  for(j = 0; j < imageHorizontal*3; j+=3) { //cycle through columns
      R =  (float) (*(imageAddress + i*columnSize+j));  //apply multiplication to each element
      G =  (float) (*(imageAddress + i*columnSize+j+1));  //apply multiplication to each element
      B =  (float) (*(imageAddress + i*columnSize+j+2));  //apply multiplication to each element
			//printf("R = %f\n", R);
			//printf("G = %f\n", G);
			//printf("B = %f\n", B);

      Y = (0.299 * R) + (0.587 * G) + (0.114 * B);
      U = (B - Y) * 0.565;
      V = (R - Y) * 0.713;
      UV = U + V;
      R1=R*0.299;
      R2=R*0.587;
      R3=R*0.114;
      G1=G*0.299;
      G2=G*0.587;
      G3=G*0.114;
      B1=B*0.299;
      B2=B*0.587;
      B3=B*0.114;
      R4=(R1+R2+R3)/3;
      G4=(G1+G2+G3)/3;
      B4=(B1+B2+B3)/3;
      I1= (unsigned char) ((R4+G4+B4+UV)/4);

			//printf("Calculate I1 = %f\n", ((R4+G4+B4+UV)/4));
			//printf("Actual I1 = %d\n", I1);


      //*((unsigned int*)(grayed +  k)) = I1;
			grayed[k] = I1;

			//printf("SDRAM store: %d\n", *(unsigned int*)(grayed +  k));
      k++;
    }
  }
}

void print(){
	unsigned int i, j;
	unsigned int value;
	for(i=0; i < imageHorizontal*numberOfRows; i++){
		value = grayed[i];
		for(j=0;j<3;j++){
			printf("%d\n", value);
		}
	}
}

int main()
{

	while(1){
		while(1){
					if(*cpus_wait == 1) {
						break;
					}
				}
		numberOfRows = *rowNumber;
		grayscale();
		*cpu_3_wait = 1;
		#ifdef DEBUG
		print();
		break;
		#endif
	}

  /* Event loop never exits. */
  while (1);

  return 0;
}
