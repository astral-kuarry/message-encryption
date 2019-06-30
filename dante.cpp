

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void swap(int *xp, int *yp);
void sort(int arr[], int n);
void printArray(int arr[], int size);
string intToString (int arry[], int size);

int main() {
    int mark[5] = {19, 10, 8, 17, 9};
    sort(mark, 5);
    printArray(mark, 5);
    string s = "THIS IS A TEST";
    int test[] = {1,2,3,4,5,34,234,234,13,23,23,2};
    int size = sizeof(test)/sizeof(test[0]);
    cout << intToString(test, size) << "\n";
    //printf("%s\n", intToString(test, size));

    //string encoded = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
    //cout << "\n" << encoded << "\n";


    //  You can also assign directly to a string.
    //str = "This is another string";

    // or
    //str = arr;
	return 0;
}
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
// A function to implement bubble sort 
void sort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

string intToString (int arry[], int size){
    string outputString = "";
    for (int i = 0; i < size; i++){
        std::string str = std::to_string(arry[i]);   
        outputString = outputString + str;
    }
    return outputString;
}