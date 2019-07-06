#include "helpers.h"
#include <iostream>
#include <string>
#include <array>
#include <stdio.h>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <math.h>
#include <sstream>
#include <iomanip>

helpers::helpers() {
	//constructor

}

helpers::~helpers() {
	// TODO Auto-generated destructor stub
}

void helpers::swap(int *xp, int *yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
// A function to implement bubble sort 
void helpers::sort(int arr[], int n) { 
   int i, j; 
   for (i = 0; i < n-1; i++)       
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
void helpers::printArray(int arr[], int size) { 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
