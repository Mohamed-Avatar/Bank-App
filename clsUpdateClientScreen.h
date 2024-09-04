#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsValidate.h"
#include"clsMainBar.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include<iomanip>
using namespace std;
class clsUpdateClientScreen:clsMainBar
{
	static void  _ReadClient(clsBankClient& Client)
	{
		cout << setw(36) << " ";
		Client.FirstName = clsInputValidate::ReadString("Enter First Name ?");
		cout << setw(36) << " ";
		Client.LastName = clsInputValidate::ReadString("Enter Last Name ?");
		cout << setw(36) << " ";
		Client.Email = clsInputValidate::ReadString("Enter Email ?");
		cout << setw(36) << " ";

		Client.Phone = clsInputValidate::ReadString("Enter  Phone ?");
		cout << setw(36) << " ";

		Client.PinCode = clsInputValidate::ReadString("Enter PinCode ?");
		cout << setw(36) << " " << "Enter Account Blance ?";

		Client.AccountBalance = clsInputValidate::ReadFloNumber();


	}
	
public :
	static void ShowUpdateClientScreen() {
		string Title = "Update Client Screen ";
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
		cout << setw(36) << " " << "Are you sure do you want to update this client [Y/N]?" << endl;
		cout << setw(36) << " " ;cin >> An;

		if (toupper(An) == 'Y') {
			clsBankClient::enSaveResults SaveResult;
			_ReadClient(Obj);
			SaveResult = Obj.Save();

		}
		else {

			cout << setw(36) << " " << "Client Not Updated " << endl;

		}


	}





















};

