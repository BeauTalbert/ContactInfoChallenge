#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;
class ContactInfo {
public:
	//gets
	string getName() {
		return name;
	}
	string getPhoneNumber() {
		return phoneNumber;
	}
	string getEmailAddress() {
		return emailAddress;
	}
	ContactInfo getContactInfo(string document);
private:
	string name;
	string phoneNumber;
	string emailAddress;

};
