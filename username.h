/*
 * username.h
 *
 *  Created on: Jun 28, 2019
 *      Author: dsana
 */
#include <string>
#include <cstring>
using namespace std;

#ifndef USERNAME_H_
#define USERNAME_H_


class username {
public:
	username(string date, string text);	
	virtual ~username();
	long long getFrac(long double input, int numDigits);
	bool checkPrime(int number);
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
	int stringRemoveNonAlphaNum(char *str);
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
private:

};

#endif /* USERNAME_H_ */
