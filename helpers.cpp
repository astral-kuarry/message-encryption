#include "headers/helpers.h"
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



helpers::helpers(bool ver) {
	verbose = ver;

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

void helpers::printIntArray(int arr[], int size) { 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

void helpers::printCharArray(char arr[], int size) { 
    int i; 
    for (i=0; i < size; i++) 
        printf("%c ", arr[i]); 
    printf("\n"); 
} 

void helpers::log(string input){
    if (verbose == true){
        cout << input << endl;
    }
}

void helpers::log(int input){
    if (verbose == true){
        cout << input << endl;
    }
}
// Remove non-alphanumeric characters
int helpers::stringRemoveNonAlphaNum(char *str)
{
    unsigned long i = 0;
    unsigned long j = 0;
    char c;
    int loops = 0;
    while ((c = str[i++]) != '\0')
    {
        if (isalnum(c) && !isdigit(c))
        {
            str[j++] = c;
        }else{
            loops++;
        }
    }
    return loops;
}

