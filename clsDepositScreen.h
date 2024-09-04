#pragma once
#include<iostream>
#include"clsMainBar.h"
#include"clsTransactionScreen.h"
#include"clsBankClient.h"
using namespace std;
class clsDepositScreen:clsMainBar
{
public :
	static void ShowDepositScreen() {
		cout << setw(36) << " " << "__________________________________" << endl;
		cout << setw(36) << " " << "         Deposit Screen   " << endl;
		cout << setw(36) << " " << "__________________________________" << endl;
		string AccountNo = clsInputValidate::ReadString("Enter Account Number ");
		clsBankClient Client = clsBankClient::Find(AccountNo);
		Client.Print();
		cout << "_________________________________________" << endl;
		double Amount = 0;
		cout << "How Much Do you want to add ?" << endl;
		cin >> Amount;
		char An = 'y';
		cout << "Are You Sure Do You Want TO Deposit ?[Y/N]" << endl;
		cin >> An;
		if (toupper(An) == 'Y') {
			clsBankClient::_Process(Client, Amount);
			clsBankClient::enSaveResults SaveResult;
			SaveResult = Client.Save();
			cout << "Deposit Successfuly \n";
		}
		else {
			cout << "Deposit Failed " << endl;
			
		}
	}








};


