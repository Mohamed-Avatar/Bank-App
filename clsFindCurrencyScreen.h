#pragma once
#include<iostream>
#include"clsMainBar.h"
#include"clsValidate.h"
#include"clsCurrency.h"
#include"clsCurrencyExchangemMainScreen.h"
#include<iomanip>
#include<vector>
#include<fstream>
#include<vector>
#include<string>
#include"clsValidate.h"
using namespace std;
class clsFindCurrencyScreen:clsMainBar
{
	enum enFindOptions{BYCODE=1,BYCOUNTRY=2};
	static void Print(clsCurrency Cu) {
		if (!Cu.IsEmpty()) {

			cout << "______________________________________________" << endl;
			cout << "Country :" << Cu.Country() << endl;
			cout << "Currency Code  :" << Cu.CurrencyCode() << endl;
			cout << "Currency Name  :" << Cu.CurrencyName() << endl;
			cout << "Rate :" << Cu.Rate() << endl;
			cout << "______________________________________________" << endl;


		}
		else {



			cout << "Currency Not Found :(" << endl;
		}
	}
	static void FindByCode() {
		string Ch = "";
		cout << "Enter Your Code ?" << endl;
		cin >> Ch;
		clsCurrency Cu = clsCurrency::FindByCode(Ch);
		Print(Cu);
	}
   
	static void FindByCountry() {
		string Ch = "";
		cout << "Enter  Country ?" << endl;
		cin >> Ch;
		clsCurrency Cu = clsCurrency::FindByCountry(Ch);
		Print(Cu);
	}

	static void PerformeFindScreen(enFindOptions Choice) {

	
		switch (Choice)
		{
		case clsFindCurrencyScreen::BYCODE:
			FindByCode();
			break;
		case clsFindCurrencyScreen::BYCOUNTRY:
			FindByCountry();
			break;
		default:
			break;
		}
		










	}




public :
	static void ShowFindCurrencyScreen() {
		_DrawScreenHedaer("Find Currency ");
		int Choice;
		cout << "Find By [1]Code [2]Country ?" << endl;
		Choice = clsInputValidate::ReadIntNumberBetween(1, 2);
		PerformeFindScreen((enFindOptions)Choice);
     }
};

