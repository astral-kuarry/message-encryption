

#include <iostream>
#include <string>
#include <array>
#include <stdio.h>
#include <cstring>

using namespace std;

void swap(int *xp, int *yp);
void sort(int arr[], int n);
void printArray(char arr[], int size);
string intToString (int arry[], int size);
string getTextKey(string message);
int countSpaces( char str[], int n );

int main() {
    int mark[5] = {19, 10, 8, 17, 9};
    sort(mark, 5);
    //printArray(mark, 5);
    string s = "THIS IS A TEST";
    int test[] = {1,2,3,4,5,34,234,234,13,23,23,2};
    int size = sizeof(test)/sizeof(test[0]);
    //cout << intToString(test, size) << "\n";
    cout << getTextKey("People who have met their online friends, what made you instantly regret it?") << "\n";
    cout << getTextKey("What are some things you realised too late in life?") << "\n";
    cout << getTextKey("\"Bottas is the meat in a ferrari sandwitch ")<< "\n";
    cout << getTextKey("e ")<< "\n";
    cout << getTextKey(" sd d d")<< "\n";
    cout << getTextKey("ewer wer wer werw erw erw er wer wer wer wer wer wer wer werwer wer wer ")<< "\n";
    cout << getTextKey("                     werwerwere")<< "\n";

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
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
void printArray(char arr[], int size) 
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

 
string getTextKey(string message){ 
    int i, j, k, l, m;
    char messageArry[message.size()+1];
    strcpy(messageArry, message.c_str());
    int size = sizeof(messageArry)/sizeof(*messageArry);
    int spaces = 0;
    for(unsigned int iLoop = 0; iLoop < size; iLoop++ )
        if(messageArry [iLoop] == ' ' )
            spaces++;
    char finalArry[10];
    int count = 0; 
    for (i = 0; messageArry[i]; i++) 
        if (messageArry[i] != ' ') 
            messageArry[count++] = messageArry[i];                    
    messageArry[count] = '\0'; 
    if (count > 10){
        for (l= 0; l < 10; l++){
            finalArry[l] = messageArry[l];
            finalArry[l] = toupper(finalArry[l]);
        }
        finalArry[10] = '\0';
    }
    if (count < 10){
        for ( k = 0; k < count; k++){
            finalArry[k] = messageArry[k];
            finalArry[k] = toupper(finalArry[k]);
        }
        for (l = k; l < 10; l++){
            finalArry[l] ='X';
        }
    } else {
        for (m = 0; m < 10; m++){
            finalArry[m] = toupper(finalArry[m]);
        }
    }
    finalArry[10] = '\0';
    return string(finalArry);
    
}
