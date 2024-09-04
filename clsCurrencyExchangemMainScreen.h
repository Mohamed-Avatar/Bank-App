#pragma once
#include<iostream>
#include"clsMainBar.h"
#include"clsValidate.h"
#include"clsCurrency.h"
#include<iomanip>
#include<vector>
#include<fstream>
#include"clsCurrencyListScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clcCurrencyClacScreen.h"
#include<vector>
#include<string>
using namespace std;
	class clsCurrencyExchangemMainScreen :clsMainBar
	{

		string _Country;
		string _CurrencyCode;
		string _CurrencyName;
		float _Rate;



		static void _ShowCurrencyList2() {
			clsCurrencyListScreen::ShowCurrencyList();


		}
		static void _FindCurrency2() {
			clsFindCurrencyScreen::ShowFindCurrencyScreen();


		}
		static void _UpdateRate2() {
			clsUpdateCurrencyScreen::ShowUpdateCurrency();


		}
		static void _CurrencyCode2() {
			clcCurrencyClacScreen::ShowCalclutor();


		}
		
	
	public:
	
		enum enCurrencyOPtions {
			pShowCurrencyList = 1, pFindCurrency = 2, pUpdateRate = 3, pCurrencyCode = 4, pMainMenu = 5
		};
		static void _PerformeCurrencyOption(enCurrencyOPtions Option) {
			switch (Option)
			{
			case enCurrencyOPtions::pShowCurrencyList:
				system("cls");
				_ShowCurrencyList2();
				GoBackToShowCurrencyMenu();
				break;
			case enCurrencyOPtions::pFindCurrency:
				system("cls");
				_FindCurrency2();
				GoBackToShowCurrencyMenu();
				break;
			case enCurrencyOPtions::pUpdateRate:
				system("cls");
				_UpdateRate2();
				GoBackToShowCurrencyMenu();
				break;
			case enCurrencyOPtions::pCurrencyCode:
				system("cls");
				_CurrencyCode2();
				GoBackToShowCurrencyMenu();
				break;
			case enCurrencyOPtions::pMainMenu:
				break;
			}






		}
		static void ShowCurrncyMainMenu() {

			_DrawScreenHedaer("Currency Exchange  Screen");

			cout << setw(36) << " " << "[1] Show Currency List " << endl;
			cout << setw(36) << " " << "[2] Find Currency   " << endl;
			cout << setw(36) << " " << "[3] Update  Currency    " << endl;
			cout << setw(36) << " " << "[4] Currency Calc   " << endl;
			cout << setw(36) << " " << "[5] Mian Menu  " << endl;
			cout << setw(36) << " " << "==============================================" << endl;
			cout << setw(36) << " " << "Enter Your Choices [1 to 5]? " << endl;
			_ReadMainMenuOption();

		}
		static void _ReadMainMenuOption() {
			int Choice = 0;
			Choice = clsInputValidate::ReadIntNumberBetween(1, 5);
			_PerformeCurrencyOption((enCurrencyOPtions)Choice);



		}
		static void  GoBackToShowCurrencyMenu() {
			cout << setw(36) << " " << "Press any Key to Go Back To Currency Menu ..." << endl;
			system("pause>0");
			system("cls");
			ShowCurrncyMainMenu();
		}

		











};

