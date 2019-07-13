#include <string>
#include <cstring>
using namespace std;

#ifndef HELPERS_H_
#define HELPERS_H_


class helpers {
public:
	helpers();
	virtual ~helpers();
    void swap(int *xp, int *yp);
    void sort(int arr[], int n);
    void printIntArray(int arr[], int size);
    void printCharArray(char arr[], int size);
    void log(string input);
    void log(int input);

private:

};

#endif /* HELPERS_H_ */
