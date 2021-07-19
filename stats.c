/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief course week 1 m1 assignment
 *
 * All the required functions implementations in the course week 1 m1 assignment
 *
 * @author Hasan Güzelmansur
 * @date 18.07.2021
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */

unsigned char min = 0;
unsigned char max = 0;
float mean = 0;
unsigned char med = 0;


  /* Statistics and Printing Functions Go Here */

  printf("Orginal Array: \n");
  print_array(&test, SIZE);

  med = find_med(&test,SIZE);
  mean = find_mean(&test,SIZE);
  max = find_max(&test,SIZE);
  min = find_min(&test,SIZE);

  print_stats(mean, med, max, min);
  sort_array(&test,SIZE);
  printf("Array after sorting: \n");
  print_array(&test,SIZE);


}

/* Add other Implementation File Code Here */


void print_stats(float mean, unsigned char med, unsigned char max, unsigned char min){

  printf("Mean is %f \n", mean);
  printf("Median is %d \n", med);
  printf("Maximum is %d \n", max);
  printf("Minimum is %d \n", min);

}

void print_array(unsigned char *array, unsigned int counter){

  for (int i=0; i<counter; i++){
    printf("%d,", *(array + 1));
  }
  printf("\n");
}

unsigned char find_med(unsigned char *array, unsigned int counter){

  unsigned char median = 0;
  median = *(array + (counter / 2) - 1);
  return median;
}

float find_mean(unsigned char *array, unsigned int counter){

  unsigned int accumulator = 0;
  float mean = 0;
  for (int i=0; i<counter; i++){
    accumulator = accumulator + array[i];
  }
  printf("acc = %d \n", accumulator);
  mean = accumulator / ((float)counter);
  return mean;
}

unsigned char find_max(unsigned char *array, unsigned int counter){
  unsigned char maximum = *array; 
  for (int i=1; i<counter; i++){ 
    if (*(array + i) > maximum){
      maximum = *(array + i);
    }
    else {} 
  }
  return maximum;
}

unsigned char find_min(unsigned char *array, unsigned int counter){
  unsigned char minimum = *array; 
  for (int i=1; i<counter; i++){ 
    if (*(array + i) < minimum){
      minimum = *(array + i);
    }
    else {} 
  }
  return minimum;
}

void sort_array(unsigned char *array, unsigned int counter){
  char flag = 0; 
  unsigned char temp;
  do {
    flag =0; 
    for (int index=0; index<counter; index++){
      if (array[index] > array[index +1] || array[index] == array[index +1]) {
        continue;
      }
      else if (array[index] < array[index +1]) {
        
        temp = array[index];
        array[index] = array[index+1];
        array[index+1] = temp;

        flag = 1; 
      }
    }
  }
  while (flag == 1); 
}