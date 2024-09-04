#pragma once
#include<iostream>
using namespace std;
class clsPerson
{
private:
	string _FristName;
	string _LastName;
	string _Phone;
	string _Email;
public:
	clsPerson(string FrName, string LName, string Email, string Phone) {

		this->_FristName = FrName;
		this->_LastName = LName;
		this->_Email = Email;
		this->_Phone = Phone;
	}
	string getFristName() {

		return _FristName;
	}
	
	void setFristName(string FristName) {

		_FristName = FristName;
	}
	__declspec(property(get = getFristName, put = setFristName))string FirstName;

	string getLastName() {

		return _LastName;
	}
	void setLastName(string LastName) {

		_LastName = LastName;
	}

	__declspec(property(get = getLastName, put = setLastName))string LastName;



	string getEmail() {

		return _Email;
	}
	void setEmail(string Email) {

		_Email = Email;
	}
	__declspec(property(get = getEmail, put = setEmail))string Email;


	string getPhone() {

		return _Phone;
	}
	void setPhone(string Phone) {

		_Phone = Phone;
	}

	__declspec(property(get = getPhone, put = setPhone))string Phone;

















};

