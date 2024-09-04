#pragma once
#include<iostream>
#include"clsMainBar.h"
#include"clsValidate.h"
#include"clsCurrency.h"
#include<iomanip>
#include<vector>
using namespace std;
class clsCurrencyListScreen:clsMainBar
{
	static void Print(clsCurrency Currncy) {

		cout << setw(8) << left << "" << "| " << setw(25) << Currncy.Country();
		cout << "| " << setw(12) << left << Currncy.CurrencyCode();
		cout << "| " << setw(29) << left << Currncy.CurrencyName();
		cout << "| " << setw(12) << left << Currncy.Rate();



	}
   
public :
	static void ShowCurrencyList() {
		vector<clsCurrency>vClients = clsCurrency::GetCurrenciesList();
		_DrawScreenHedaer("Currency List ");
		cout << setw(8) << left << "" << "| " << setw(25) << "Country";
		cout << "| " << setw(12) << left << "Code";
		cout << "| " << setw(29) << left << "Name ";
		cout << "| " << setw(12) << left << "Rate/(1$)" << endl;;
		cout <<setw(8)<<""<<left << "_______________________________________________________________________________________" << endl;

		if (vClients.size() == 0) {
			cout << "\t\t\t\t No Clients Avalible " << endl;
		}
		else {

			for (clsCurrency C : vClients) {


				Print(C);
				cout << endl;

			}
			cout << setw(8) << left << "" << "\n\t_______________________________________________________";
			cout << "_________________________________________\n" << endl;






		}







	}










};

