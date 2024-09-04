#pragma once
#include<iostream>
#include"clsMainBar.h"
#include"clsTransactionScreen.h"
#include"clsBankClient.h"
#include<iomanip>
#include<vector>
using namespace std;
class clsToatalBlancesScreen: public clsMainBar
{
	static void PrintClientRecordBalanceLine(clsBankClient &Client){
	
		cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.FirstName + " " + Client.LastName;
		cout << "| " << setw(12) << left << Client.AccountBalance;
	
	}
public :
	static void ShowTotalBalances() {
		string Title = "Total Balnces Screen ";
		_DrawScreenHedaer(Title);

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "" << "\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;
		vector<clsBankClient>vClients = clsBankClient::GetClientsList();
		double TotalBalances = clsBankClient::GetTotalBalances();

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{
				PrintClientRecordBalanceLine(Client);
				cout << endl;
			}

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
	










	}
	


};

