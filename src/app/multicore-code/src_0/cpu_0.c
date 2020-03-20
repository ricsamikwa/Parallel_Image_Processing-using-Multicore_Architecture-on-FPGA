#include "altera_avalon_performance_counter.h"
#include "system.h"
#include <stdio.h>
#include "images.h"
#include "io.h"

#define PERFORMANCE
//#define DEBUG

#define imagesProcessed 1

#define imageHorizontal 360
#define imageVertical 260
#define numberOfRows 65

unsigned int* imageAddress = (unsigned int*) (SDRAM_BASE + 4);
unsigned char grayed[imageHorizontal*imageVertical/4];

//synchronisation flags
unsigned int* cpus_wait = (unsigned int*) (SDRAM_BASE + 30000000);
unsigned int* cpu_1_wait = (unsigned int*) (SDRAM_BASE + 30000004);
unsigned int* cpu_2_wait = (unsigned int*) (SDRAM_BASE + 30000008);
unsigned int* cpu_3_wait = (unsigned int*) (SDRAM_BASE + 30000012);

unsigned int* rowNumber = (unsigned int*) (SDRAM_BASE + 30000016);

void copy(){
	unsigned int i;
	for(i=0; i<imageHorizontal*imageVertical*3; i++){
		*(imageAddress +  i) =  ((image[i+3]));  //apply multiplication to each element
	}
}

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
	printf("P3\n# Created by GIMP version 2.10.12 PNM plug-in\n");
	printf("%d %d\n255\n", imageHorizontal, imageVertical);
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
	*cpu_1_wait = 0;
	*cpu_2_wait = 0;
	*cpu_3_wait = 0;


	delay(2500);

  int j;
	copy();

	*rowNumber = numberOfRows;
	*cpus_wait = 1;


	#ifdef PERFORMANCE
	/* Reset Performance Counter */
 PERF_RESET(P_COUNTER_BASE);
/* Start Measuring */
	PERF_START_MEASURING (P_COUNTER_BASE);
  for(j = 0; j<imagesProcessed; j++){
    PERF_BEGIN(P_COUNTER_BASE, 1);
    #endif
    grayscale();
    #ifdef DEBUG
		print();
    #endif
		while(1){
					if((*cpu_1_wait == 1)&&(*cpu_2_wait == 1)&&(*cpu_3_wait == 1)) {
						break;
					}
				}
				*cpu_1_wait = 0;
				*cpu_2_wait = 0;
				*cpu_3_wait = 0;
  #ifdef PERFORMANCE
  PERF_END(P_COUNTER_BASE, 1);
  }
#endif

#ifdef PERFORMANCE
  /* End Measuring */
  PERF_STOP_MEASURING(P_COUNTER_BASE);
  /* Print measurement report */
  perf_print_formatted_report
	 (P_COUNTER_BASE,
	  ALT_CPU_FREQ,                 // defined in "system.h"
	  1,                            // How many sections to print
	  "counter 1");    // Display-name of section(s).

    float total_time =  (float)perf_get_total_time(P_COUNTER_BASE)/(float)alt_get_cpu_freq();
    float normalized_time = total_time/(imagesProcessed*imageHorizontal*numberOfRows*4);

    float throughput = 1/normalized_time;
		printf("execution time: %f\nnormalized time: %f\nthroughput (pixels/sec): %f\n", total_time, normalized_time, throughput);
#endif

  /* Event loop never exits. */
  while (1);

  return 0;
}
