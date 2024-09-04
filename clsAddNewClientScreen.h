#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsValidate.h"
#include"clsScreen.h"
#include<iomanip>
using namespace std;
class clsAddNewClientScreen:clsMainBar
{
private :
    static void _PrintClientRecordLine(clsBankClient Client)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FirstName + " " + Client.LastName;
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }
    static void  _ReadClient(clsBankClient &Client)
    {
  
        Client.FirstName = clsInputValidate::ReadString("Enter First Name ?");

        Client.LastName = clsInputValidate::ReadString("Enter Last Name ?");

        Client.Email = clsInputValidate::ReadString("Enter Email ?");


        Client.Phone = clsInputValidate::ReadString("Enter  Phone ?");

        Client.PinCode = clsInputValidate::ReadString("Enter PinCode ?");
        cout << setw(36) << " "<< "Enter Account Blance ?";
        
        Client.AccountBalance = clsInputValidate::ReadFloNumber();
        

    }





public :
	static void ShowAddNewClientScreen() {
        system("cls");
        cout << endl;
		_DrawScreenHedaer("Adding New Client Screen ");
        string AccountNumber = "";
        cout << setw(36) << " " << "Please Enter Your Account Number ?" << endl;
        getline(cin >> ws, AccountNumber);
        while (clsBankClient::IsClientExist(AccountNumber)) {

            cout << setw(36) << " " << "Wrong ,Account Number is already Exist ." << endl;
             AccountNumber = "";
            cout << setw(36) << " " << "Please Enter Your Account Number ?" << endl;
            getline(cin >> ws, AccountNumber);





        }
        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
        _ReadClient(NewClient);
        clsBankClient::enSaveResults SaveResult;
        SaveResult=NewClient.Save();
        switch (SaveResult)
        {
        case clsBankClient::svFaildEmptyObject:
            cout << "We Cant Storage This Obj " << endl;
            break;
        case clsBankClient::svSucceeded:
            cout << "Client Adding Asuccessfuly " << endl;
            break;
        case clsBankClient::svFaildAccountNumberExists:
            cout << "We Cant Storage This Obj,Account Number Is Exist " << endl;
            break;
        default:
            break;
        }
    }






};

