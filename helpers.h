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
    void printArray(int arr[], int size);
private:

};

#endif /* HELPERS_H_ */
