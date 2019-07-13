#include <string>
#include <cstring>
#include <vector>

using namespace std;

#ifndef PASSWORD_H_
#define PASSWORD_H_


class password {
public:
    password(string rawplaintext, string rawciphertext);
    virtual ~password();
    bool getParity(long long num);
    bool checkInstruct2();
    string plaintext;
    string ciphertext;
    int m;
    int n;
private:

};

#endif /* PASSWORD_H_ */