
#include "ContactInfo.h"

ContactInfo ContactInfo::getContactInfo(string document)
{
	ContactInfo copyInfo;
	//step 1 (could change depending on information flow, 
	//assuming I get a document from the OCR but it doesn't matter, step 2 of parsing and regular expressions
	//are the important steps
	ifstream OCRFile;
	OCRFile.open(document);
	if (OCRFile.is_open()) {
		//File is open
		//Step 2, Parsing the File
		//judging off of the examples, it will be in a line by line format
		//meaning I can grab the whole line and use a regX to identify it

		//varible to save th line grabbed into before using the regX
		string mysteryContactInfo;

		//loop to get all the lines
		while (getline(OCRFile, mysteryContactInfo)) {
			//parse the line that was grabbed first and Identify if it is any contact Info,
			//If so, update the class funtion.

			//RegX for a name, Probably doesn't cover all names, but it covers alot however
			if (regex_match(mysteryContactInfo, regex("[A-Z]([a-z]|-[A-Z]|-[a-z]|')+ [A-Z]([a-z]|-[A-Z]|')+"))) {
				//Version 2 checks with the user on if the name is actually the name first
				string answer;
				cout << "Is this the correct Name: " << mysteryContactInfo << endl << "Reply yes or no: ";
				cin >> answer;
				cout << endl;
				if (answer == "yes") {
					this->name = mysteryContactInfo;
				}
			}
			//RegX for PhoneNumber
			if (regex_match(mysteryContactInfo, regex("(Phone: |Tel: )?(\\+1 )?(\\([0-9]{3}\\)[ ]?|[0-9]{3}[-]?)[0-9]{3}-[0-9]{4}"))) {

				//just incase something else is already stored in phoneNumber
				this->phoneNumber = "";

				//format the matched phone number into only digits
				for (int i = 0; i < mysteryContactInfo.length(); i++) {
					//check if the char is a digit
					if (isdigit(mysteryContactInfo[i])) {
						this->phoneNumber += mysteryContactInfo[i];
					}

				}
			}
			//RegX for EmailAddress assuming no crazy characters
			if (regex_match(mysteryContactInfo, regex("([A-Z]|[a-z])([A-Z]|[a-z]|\\.)+\\@([A-Z]|[a-z]|\\.)+"))) {
				this->emailAddress = mysteryContactInfo;
			}
		}
	}
	else {
		cout << "Error in opening the OCR File, Program terminated" << endl;
	}
	OCRFile.close();
	return copyInfo;
}
