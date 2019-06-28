//============================================================================
// Name        : message-encryption
// Author      : Dante Sanaei and Alec Leven
// Version     : pre-release
// Description : An algorithm to generate an encrypted username and password for a messaging service
//============================================================================

#include <iostream>
#include "username.h"

using namespace std;

//functions
void intro();
void input();

int main() {
	input();
	return 0;
}
 
void input(){ //Return email, message, time, and recieved keyword if recipient
	string email;
	string message;
	int time;
	int type;
	int ampm;
	cout << "Welcome to AQ Encryption v1.0" << endl;
	cout << "Enter email of recipient: ";
	cin >> email;
	cout << "Enter message: ";
}
