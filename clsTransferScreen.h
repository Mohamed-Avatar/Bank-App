#pragma once
#include<iostream>
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsFindClientScreen.h"
#include"clsValidate.h"
#include"clsBankClient.h"
#include"clsTransFerLogs.h"
class clsTransferScreen :clsMainBar
{
	static void PrintShortCard(clsBankClient Client) {
		cout << "__________________________________" << endl;
		cout << "FullName Name :" << Client.FirstName + " " + Client.LastName << endl;
		cout << "Acc Number:" << Client.AccountNumber() << endl;
		cout << "Acc Balance:" << Client.AccountBalance << endl;
		cout << "__________________________________" << endl;
	}
	static string _ReadAccountNumber() {
		string AccountNo = clsInputValidate::ReadString("Enter Account Number ?");
		while (!clsBankClient::IsClientExist(AccountNo)) {
			cout << "Account Number Is Not Exist ," << endl;

			AccountNo = clsInputValidate::ReadString("Enter Another  Account Number ?");


		}
		return AccountNo;

	}
	static double  _ReadAmount(clsBankClient Client) {
		double  Amount = clsInputValidate::ReadDblNumber2("Enter Amount  ?");
		while (Amount > Client.AccountBalance) {
			cout << "Amount is grather than Acc Balance   ," << endl;

			Amount = clsInputValidate::ReadDblNumber2("Enter Amount  ?");


		}
		return Amount;

	}
public:
	static void ShowTtansferScreen() {
		system("cls");
		_DrawScreenHedaer("Transfer Screen");
		cout << "\nTransfear From :" << endl;
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
		PrintShortCard(SourceClient);
		double Amount = _ReadAmount(SourceClient);

	
		cout << "\nTransfear To :" << endl;
		clsBankClient Destination = clsBankClient::Find(_ReadAccountNumber());
		char An = 'n';
		cout << "Do You Want TO Performe this Prosess [Y/N]" << endl;
		cin >> An;
		if (toupper(An) == 'Y') {

			if (SourceClient.Transfer(Amount, Destination)) {
				cout << "Transfer done Successfuly " << endl;
				clsTransFerLogs::RegisterTransfer(SourceClient, Destination, Amount);
			}
			else {
				cout << "Transfer Faild " << endl;
			}


		}






	}
};

