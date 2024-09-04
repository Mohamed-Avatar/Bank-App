#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsValidate.h"
#include"clsScreen.h"
#include<iomanip>
using namespace std;
class clsDeleteClientScreen : clsMainBar
{


public:
	static void ShowUpdateClientScreen() {
		string Title = "Delete  Client Screen ";
		_DrawScreenHedaer(Title);
		string AccountNumber = clsInputValidate::ReadString("Enter Account Number ?");
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << setw(36) << " " << "Wrong ,Account Number is already Exist ." << endl;
			AccountNumber = "";

			AccountNumber = clsInputValidate::ReadString("Enter Account Number ?");


		}
		clsBankClient Obj = clsBankClient::Find(AccountNumber);
		Obj.Print();
		char An = 'n';
		cout << setw(36) << " " << "Are you sure do you want to Delete  this client [Y/N]?" << endl;
		cout << setw(36) << " ";cin >> An;

		if (toupper(An) == 'Y') {
		
			Obj.Delete();
			Obj.Print();

		}
		else {

			cout << setw(36) << " " << "Client Not Deleted " << endl;

		}
	}

};