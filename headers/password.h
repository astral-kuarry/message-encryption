#include <string>
#include <cstring>
#include <vector>

using namespace std;

#ifndef PASSWORD_H_
#define PASSWORD_H_


class password {
public:
    password(string rawplaintext, string rawciphertext);
    password();
    virtual ~password();
    bool getParity(long long num);
    long long int getFrac(long double input, int numDigits);
    bool checkInstruct1();
    bool checkInstruct3();
    bool checkInstruct2();
    string getOp1(bool op4);
    string getOp2();
    string getOp3(string cipher);
    string getOp4();
    string getOp5();
    string getOp6();
    string getOp7();
    string plaintext;
    string ciphertext;
    string targetKey;
    int m;
    int n;
private:

};

#endif /* PASSWORD_H_ */