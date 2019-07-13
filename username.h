/*
 * username.h
 *
 *  Created on: Jun 28, 2019
 *      Author: dsana
 */
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#ifndef USERNAME_H_
#define USERNAME_H_


class username {
public:
	username(string date, string text);
    username();
	virtual ~username();
	bool checkPrime(long long number);
	bool checkConsonant(char letter);
	bool checkAscending(string numString);
	void countInt(string input, int inputSize, int checkArry[], int checkArrysize, int countArry[], int type);
	void countChar(string input, int inputSize, char checkArry[], int checkArrysize, int countArry[]);
	string invertLetToNum(string input);
	string invertOrder(string input);
	string digitLetShift(string input, int numDigits);
	string digitNumShift(string input, int numDigits);
	string intToString (int arry[], int size);
	string deleteDig (string input, int numDigits);
	string invertNumToLet(string input);
	string excise(string input, string excise);
	string getTableKey(string date, string text);
	bool checkOdd1(string date);
	bool checkOdd2(string date);
	bool checkOdd3(string date);
	bool checkOddA(string text);
	bool checkOddB(string text);
	bool checkOddC(string text);
	bool checkEven1(string date);
	bool checkEven2(string date);
	bool checkEven3(string date);
	bool checkEvenA(string text);
	bool checkEvenB(string text);
	bool checkEvenC(string text);
	int intToNum(int arry[], int size);
	int Mod(int a, int b);
    char** Create2DArray(int rowCount, int colCount);
    string ToUpper(string str);
    string RemoveChar(string str, char ch);
    vector<int> FindAllOccurrences(string str, char value);
    string RemoveAllDuplicates(string str, vector<int> indexes);
    string Decipher(string input, string key);
    string Encipher(string input, string key);
    string Cipher(string input, string key, bool encipher);
    string AdjustOutput(string input, string output);
    string RemoveOtherChars(string input);
    char* DifferentRowColumn(char** keySquare, int row1, int col1, int row2, int col2);
    char* SameRowColumn(char** keySquare, int row, int col, int encipher);
    char* SameColumn(char** keySquare, int col, int row1, int row2, int encipher);
    char* SameRow(char** keySquare, int row, int col1, int col2, int encipher);
    void GetPosition(char** keySquare, char ch, int* row, int* col);
    char** GenerateKeySquare(string key);
    string keyword;
    string plaintext;
    string ciphertext;



private:

};

#endif /* USERNAME_H_ */
