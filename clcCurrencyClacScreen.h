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
class clcCurrencyClacScreen:clsMainBar
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
	static float Operation(clsCurrency FristCurrency, clsCurrency SecoundCurrency) {
		clsCurrency USA = clsCurrency::FindByCode("usd");
		float Amount;
		float AmountAfter;
		cout << "How Much Do you Want To Add ?" << endl;
		cin >> Amount;
		if (SecoundCurrency.CurrencyCode() == USA.CurrencyCode()) {

			AmountAfter = (Amount / FristCurrency.Rate());



		}
		else {




			AmountAfter = (Amount / FristCurrency.Rate()) * SecoundCurrency.Rate();


		}




		return AmountAfter;









	}
public:
	static void ShowCalclutor() {
		string FirstCode="";
		cout << "________________From______________" << endl;
		cout << "Enter Your Frist Code " << endl;
		cin >> FirstCode;
		clsCurrency FristCurrency = clsCurrency::FindByCode(FirstCode);
		while (!FristCurrency.IsCurrencyExist(FirstCode)) {
			cout << "Invalide Currency Code " << endl;
			FirstCode = "";
			cout << "Enter Your Frist Code " << endl;
			cin >> FirstCode;
		}
		_Print(FristCurrency);
		cout << "________________To______________" << endl;

		string SecondCode = "";
		cout << "Enter Your Second Code  " << endl;
		cin >> SecondCode;
		clsCurrency SecoundCurrency = clsCurrency::FindByCode(SecondCode);
		while (!SecoundCurrency.IsCurrencyExist(SecondCode)) {
			cout << "Invalide Currency Code " << endl;
			SecondCode = "";
			cout << "Enter Your Frist Code " << endl;
			cin >> SecondCode;
		}
		_Print(SecoundCurrency);
		cout << "______________________________________________" << endl;
		cout << Operation(FristCurrency, SecoundCurrency) << endl;
	}















};

