#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsValidate.h"
#include"clsScreen.h"
#include<iomanip>
using namespace std;
class clsFindClientScreen:clsMainBar
{
public :
	static void ShowFindScreen() {
        system("cls");
		string Title = "Show Find Client Screen ";
		_DrawScreenHedaer(Title);
        string AccountNumber = "";
        cout << setw(36) << " " << "Please Enter Your Account Number ?" << endl;
        getline(cin >> ws, AccountNumber);
        while (!clsBankClient::IsClientExist(AccountNumber)) {

            cout << setw(36) << " " << "Wrong ,Account Number is Not  Exist ." << endl;
             AccountNumber = "";
            cout << setw(36) << " " << "Please Enter Your Account Number ?" << endl;
            getline(cin >> ws, AccountNumber);

        }
        clsBankClient Obj=clsBankClient::Find(AccountNumber);
        Obj.Print();






	}







};

