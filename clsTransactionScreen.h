#pragma once
//Add WithDraw And Deposit in Another Class 
#include<iostream>
#include"clsBankClient.h"
#include"clsValidate.h"
#include"clsMainBar.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h";
#include"clsDeleteClientScreen.h"
#include"clsScreen.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsToatalBlancesScreen.h"
#include"clsTransferScreen.h"
#include"clsShowTransferScreen.h"
#include<iomanip>
using namespace std;
class clsTransactionScreen:clsMainBar
{
	enum enTransactionOption{Deposit=1,WithDraw=2,TotalBlances=3,Transfer=4,TransferScreen=5,BacktoMainMenu=6};
	static void _PerformeTransactionoption(enTransactionOption Ch) {
		switch (Ch)
		{
		case clsTransactionScreen::Deposit:
			_Deposit();
			_GoBackTOTransactionMenu();
			break;
		case clsTransactionScreen::WithDraw:
			_WithDraw();
			_GoBackTOTransactionMenu();
			break;
		case clsTransactionScreen::TotalBlances:
			_TotalBlances();
			_GoBackTOTransactionMenu();
			break;
		case clsTransactionScreen::Transfer:
			_ShowTransferScreen();
			_GoBackTOTransactionMenu();
			break;
		case clsTransactionScreen::TransferScreen:
			_ShowTransferScreenList();
			_GoBackTOTransactionMenu();
			break;
		case clsTransactionScreen::BacktoMainMenu:
			
			break;
		default:
			break;
		}
	}
	static void _ReadTransactionMenu() {
		int Choice = 0;
		Choice = clsInputValidate::ReadIntNumberBetween(1, 6);
		_PerformeTransactionoption((enTransactionOption)Choice);



	}
	
	static void _Deposit() {
		clsDepositScreen::ShowDepositScreen();
	}
	static void _WithDraw() {
		clsWithdrawScreen::_WithDraw();
	}
	static void _TotalBlances() {
		clsToatalBlancesScreen::ShowTotalBalances();
	}
	static void _ShowTransferScreen() {
		clsTransferScreen::ShowTtansferScreen();
	}
	static void _ShowTransferScreenList() {
		clsShowTransferScreen::ShowTransferList();
	}
public :
	static void TransactionScreen() {
		system("cls");
		_DrawScreenHedaer("Transaction Screen");

		cout << setw(36) << " " << "[1] Deposit " << endl;
		cout << setw(36) << " " << "[2] WithDraw " << endl;
		cout << setw(36) << " " << "[3] Total Blances  " << endl;
		cout << setw(36) << " " << "[4] Transfer  " << endl;
		cout << setw(36) << " " << "[5] Transfer List " << endl;
		cout << setw(36) << " " << "[6]Go Back To MainMenu " << endl;
	
		cout << setw(36) << " " << "==============================================" << endl;
		cout << setw(36) << " " << "Enter Your Choices [1 to 6]? " << endl;
		_ReadTransactionMenu();
	}





	static void _GoBackTOTransactionMenu() {

		cout << endl;
		cout << setw(36) << " " << "Press any Key To Go Back Main Menu ...." << endl;
		cout << setw(36) << " ";
		system("Pause>0");
		cout << setw(36) << " ";
		system("cls");
		cout << setw(36) << " " << endl;;
		TransactionScreen();

	}




};

