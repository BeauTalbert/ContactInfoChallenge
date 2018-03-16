#include <iostream>

#include "ContactInfo.h"
using namespace std;

int main(int argc, char *argv[]) {
	ContactInfo contactIn;
	contactIn.getContactInfo(argv[1]);
	//print out the information
	cout << "Name: " << contactIn.getName() << endl;
	cout << "Phone: " << contactIn.getPhoneNumber() << endl;
	cout << "Email: " << contactIn.getEmailAddress() << endl;

	
	//system("pause");
	return 0;
}