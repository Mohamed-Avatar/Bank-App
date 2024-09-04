#pragma once
#include<iostream>
#include"clsMainBar.h"
#include"clsTransactionScreen.h"
#include"clsBankClient.h"
using namespace std;
class clsWithdrawScreen

{

public :

	static void _WithDraw() {
		cout << endl;
		cout << setw(36) << " " << "__________________________________" << endl;
		cout << setw(36) << " " << "         WithDraw Screen   " << endl;
		cout << setw(36) << " " << "__________________________________" << endl;

		string AccountNo = clsInputValidate::ReadString("Enter Account Number ");
		clsBankClient Client = clsBankClient::Find(AccountNo);
		Client.Print();
		cout << "_________________________________________" << endl;
		double Amount = 0;
		cout << "How Much Do you want to WithDraw ?" << endl;
		cin >> Amount;
		while (Client.AccountBalance < Amount) {
			cout << "You don't have much money to withdraw " << endl;
			Amount = 0;
			cout << "How Much Do you want to WithDraw ?" << endl;
			cin >> Amount;

		}
		char An = 'y';
		cout << "Are You Sure Do You Want TO WithDraw ?[Y/N]" << endl;
		cin >> An;
		if (toupper(An) == 'Y') {
			clsBankClient::_Process(Client, Amount);
			clsBankClient::enSaveResults SaveResult;
			SaveResult = Client.Save();
			cout << "WithDarw  Successfuly \n";
		}
		else {
			cout << "WithDraw Failed " << endl;
			
		}
	}

};

