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
class clsUpdateCurrencyScreen :clsMainBar
{


	static void _Print(clsCurrency Cu) {
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







public :
	static void ShowUpdateCurrency() {
		_DrawScreenHedaer("Update Rate ") ;
		string CurrencyCode = "";
		cout << "Enter Your Currency Code " << endl;
		cin >> CurrencyCode;
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_Print(Currency);
		if (Currency.IsCurrencyExist(CurrencyCode)) {
			float Rate;
			cout << "Enter New Rate ?" << endl;
			cin >> Rate;
			Currency.UpdateRate(Rate);

			cout << "Currency Updated Succrssfuly :)" << endl;
		}



	}











};

