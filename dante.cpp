

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

using namespace std;

void swap(int *xp, int *yp);
void sort(int arr[], int n);
void printArray(int arr[], int size);
string intToString (int arry[], int size);
string getTextKey(string message);     
int countSpaces( char str[], int n );
int stringRemoveNonAlphaNum(char *str);
string getDateKey();
long long getFrac(long double input, int numDigits);
bool checkPrime(int number);
bool checkConsonant(char letter);
bool checkAscending(string numString);
void count(string input, char checkArry[], int countArry[]);

int main() {
    int mark[5] = {19, 10, 8, 17, 9};
    sort(mark, 5);
    printArray(mark, 5);
    string s = "THIS IS A TEST";
    int test[] = {1,2,3,4,5,34,234,234,13,23,23,2};
    int size = sizeof(test)/sizeof(test[0]);
    cout << intToString(test, size) << "\n";
    cout << getTextKey("People who have met their online friends, what made you instantly regret it?") << "\n";
    cout << getTextKey("What are some things you realised too late in life?") << "\n";
    cout << getTextKey("\"Bott!23as is the meat in a ferrari sandwitch ")<< "\n";
    cout << getTextKey("  test§¶•hªº–≠ test ")<< "\n";
    cout << getTextKey("Formula.1.2019x09.Austria.Race.SkyF1HD.Smcgill1969")<< "\n";
    cout << getTextKey("Men, what things do you enjoy that are typically considered “girly”?")<< "\n";
    cout << getTextKey("  123werwerwere")<< "\n";
    cout << getDateKey() << endl;
    cout << "True Primne: " << checkPrime(997) << endl << "False Prime: " << checkPrime(38) << endl;
    cout << "False Consonant: " << checkConsonant('E') << endl;
    cout << checkAscending("111111567811") << endl;
    //string encoded = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
    //cout << "\n" << encoded << "\n";
    int countArry[100];


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
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

//Converts int array to a string
string intToString (int arry[], int size){
    string outputString = "";
    for (int i = 0; i < size; i++){
        std::string str = std::to_string(arry[i]);   
        outputString = outputString + str;
    }
    return outputString;
}

//Get text from user and converts it to TextKey
string getTextKey(string message){ 
    int i, j, k, l, m;
    char messageArry[message.size()+1];
    strcpy(messageArry, message.c_str());
    int size = sizeof(messageArry)/sizeof(*messageArry);
    int spaces = 0;
    for(unsigned int iLoop = 0; iLoop < size; iLoop++ )
        if(messageArry [iLoop] == ' ' )
            spaces++;
    char finalArry[11];
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
    int loops = stringRemoveNonAlphaNum(finalArry);
    if (loops > 0){
        for (int t = 9-loops+1; t < 10; t++){
            finalArry[t] = 'X';
        }     
    }
    string finalString = string(finalArry);
    return finalString;
}

// Remove non-alphanumeric characters
int stringRemoveNonAlphaNum(char *str)
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

// Get date key
string getDateKey(){
    std::time_t rawtime;
    std::tm* timeinfo;
    char datestring [80];
    int dateInt[14];
    int firstSeven[7];
    int lastSeven[7];
    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);
    std::strftime(datestring,80,"%Y%m%d%H%M%S",timeinfo);
    datestring[14] = '\0';
    for (int i = 0; i < 14;i++){
        dateInt[i] = datestring[i] - '0';
    }
    for (int j = 0; j < 7; j++){
        firstSeven[j] = dateInt[j];
    }
    for (int k = 0; k < 7; k++){
        lastSeven[k] = dateInt[k + 7];
    }
    int firstSevenInt = 0;
    int lastSevenInt = 0;
    for (int j = 0; j < 7; j++) {
        firstSevenInt *= 10;
        firstSevenInt += firstSeven[j];
        lastSevenInt *= 10;
        lastSevenInt += lastSeven[j];
    }
    long double getFracInput = (long double) firstSevenInt / lastSevenInt;
    long long dateKeyInt = getFrac(getFracInput, 12);
    std::stringstream ss;
    ss << std::setw(12) << std::setfill('0') << dateKeyInt;
    std::string finalString = ss.str();
    return finalString;
}

// Alec
long long int getFrac(long double input, int numDigits) {
    long double result;
    long double intpart;
    long double fractpart;
    fractpart = modf(input , &intpart);
    if (fractpart != 0.0) {
        while (fractpart < 0.1) {
            fractpart *= 10;
        }
    }
        
    for (int i = 1; i <= numDigits; i++) {
        fractpart *= 10;
    }
    return round(fractpart);
}

// Check if a number is prime
bool checkPrime(int number){
    int flag = 1;
    for (int i = 2; i <= sqrt(number) / 2; i++) {  
        if (number % i == 0) { 
            flag = 0; 
            break; 
        } 
    } 
    if (flag == 1) { 
        return true;
    } 
    return false; 
}

// Check if a letter is a consonant
bool checkConsonant(char letter){
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    int i;
    for (i = 0; i < 5; i++){
        if (letter == vowels[i] || letter == toupper(vowels[i])){
            return false;
        }
    }
    return true;
}

// Check if there is a series of four ascending numbers in the date key
bool checkAscending(string numString){
    char numStringArry[120];
    int numIntArry[120];
    int i,j;
    strcpy(numStringArry, numString.c_str());
    for (i = 0; i < 12; i++){
        numIntArry[i] = numStringArry[i] - '0';
    }
    for (j = 0; j < 9; j++){
        if ( ((numIntArry[j] + 1) == numIntArry[j+1]) && ((numIntArry[j] + 2) == numIntArry[j+2]) && ((numIntArry[j] + 3) == numIntArry[j+3])){
            return true;
        }
    }
    return false;
}

// count how many of certain characters exist in a string
void count(string input, char checkArry[], int countArry[]){

}
