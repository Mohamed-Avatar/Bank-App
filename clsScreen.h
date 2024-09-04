#pragma once
#include<iostream>
#include"clsCurrencyExchangemMainScreen.h"
#include"clsBankClient.h"
#include"clsValidate.h"
#include"clsMainBar.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h";
#include"clsDeleteClientScreen.h"
#include"clsTransactionScreen.h"
#include"clsMangeUsersScreen.h"
#include"clsLoginsRegistureScreen.h"
#include"clsCurrency.h"
#include"Globail.h"
#include<iomanip>
 
using namespace std;
class clsScreen :clsMainBar
{

enum enMainScreen{ShowList=1,AddNew=2,Update=3,Delete=4,Find=5,TrsnsAction=6,MangeUsers=7,ShowRegisturScreen=8,CurrncyExchange=9,Exit=10};
static void _PerformeMainMenuOption(enMainScreen  Choice) {
	switch (Choice)
	{
	case clsScreen::ShowList:
		system("cls");
		
		_ShowAllClientScreen();
		GoBackToMainMenu();
		break;
	case clsScreen::AddNew:
		system("cls");
		
		_ShowAddNewClientScreen();
		GoBackToMainMenu();


		break;
	case clsScreen::Update:
		system("cls");

		_ShowUpdateClientScreen();
		GoBackToMainMenu();


		break;
	case clsScreen::Delete:

		system("cls");
	
		_ShowDeleteClientScreen();
		GoBackToMainMenu();


		break;
	case clsScreen::Find:
		system("cls");

		_ShowFindClientScreen();
		GoBackToMainMenu();


		break;
	case clsScreen::TrsnsAction:
		system("cls");
		
		_ShowTransActionScreen();
		GoBackToMainMenu();


		break;
	case clsScreen::Exit:

		system("cls");
	
		_ShowLogoutScreen();
	

		
		break;
	case clsScreen::MangeUsers:
		   system("cls");
		   _ShowMangeUsersScreen();
		   GoBackToMainMenu();
		   break;
	case clsScreen::ShowRegisturScreen:
		system("cls");
		_ShowLoginsRegistureScreen();
		GoBackToMainMenu();
		break;

	case clsScreen::CurrncyExchange:
		system("cls");
		_ShowCreencyExchangeScreen();
		GoBackToMainMenu();
		break;



	}
	






}
static void _ReadMainMenuOption() {
	int Choice = 0;
	Choice = clsInputValidate::ReadIntNumberBetween(1, 10);
	_PerformeMainMenuOption((enMainScreen)Choice);



}
static void _ShowAllClientScreen() {
	if (!ShowAcsessRight(clsUser::pListCLient)) {
		return;
	}
	clsClientListScreen::ShowClientsList();
}
static void _ShowTransActionScreen() {
	if (!ShowAcsessRight(clsUser::pTreansactionMenu)) {
		return;
	}
	clsTransactionScreen::TransactionScreen();
}
static void _ShowAddNewClientScreen() {
	if (!ShowAcsessRight(clsUser::pAddNewClient)) {
		return;
	}
	clsAddNewClientScreen::ShowAddNewClientScreen();

}

static void _ShowFindClientScreen() {
	if (!ShowAcsessRight(clsUser::pFindCLient)) {
		return;
	}
	clsFindClientScreen::ShowFindScreen();


}

static void _ShowUpdateClientScreen() {
	if (!ShowAcsessRight(clsUser::pUdateClient)) {
		return;
	}
	clsUpdateClientScreen::ShowUpdateClientScreen();

}

static void _ShowDeleteClientScreen() {
	if (!ShowAcsessRight(clsUser::pDeleteClient)) {
		return;
	}
	clsDeleteClientScreen::ShowUpdateClientScreen();

}

static void _ShowMangeUsersScreen() {
	if (!ShowAcsessRight(clsUser::pMangeUsers)) {
		return;
	}
	
	clsMangeUsersScreen::MangeUsersScreen();
}
static void _ShowLoginsRegistureScreen() {
	if (!ShowAcsessRight(clsUser::pLoginsScreen)) {
		return;
	}
	clsLoginRegisterScreen::ShowLoginRegisterScreen();
	
}
static void _ShowCreencyExchangeScreen() {
	if (!ShowAcsessRight(clsUser::pCurrencyEcxhange)) {
		return;
	}
	clsCurrencyExchangemMainScreen::ShowCurrncyMainMenu();

}
static void _ShowLogoutScreen() {

	CurrentUser = clsUser::Find("", "");
	

}

public :
	static void MainScreen() {
		system("cls");
		_DrawScreenHedaer("Main Screen");
		cout<<setw(36)<<" "<< "==========================================" << endl;
		cout<<setw(36)<<" "<< "               Main MenuScreen             " << endl;
		cout<<setw(36)<<" "<< "==============================================" << endl;
		cout<<setw(36)<<" "<< "[1] Show Clients List " << endl;
		cout<<setw(36)<<" "<< "[2] Add New Client    " << endl;
		cout<<setw(36)<<" "<< "[3] Update  Client    " << endl;
		cout<<setw(36)<<" "<< "[4] Delete  Client    " << endl;
		cout<<setw(36)<<" "<< "[5] Find Client       " << endl;
		cout<<setw(36)<<" "<< "[6] Transacrion Menu  " << endl;
		cout<<setw(36)<<" "<< "[7] MangeUsers Menu   " << endl;
		cout<<setw(36)<<" "<< "[8] Login Registure  " << endl;
		cout <<setw(36)<<" "<<"[9] Currency Exchange   " << endl;
		cout <<setw(36)<<" "<<"[10] Logout" << endl  ;  

		cout << setw(36) << " " << "==============================================" << endl;
		cout<<setw(36)<<" "<< "Enter Your Choices [1 to 8]? " << endl;
		_ReadMainMenuOption();
	}
	static void  GoBackToMainMenu() {
		cout << setw(36) << " ";
		cout << "Press any Key To Go Back Main Menu ...." << endl;
		cout << setw(36) << " ";
		system("Pause>0");
		cout << setw(36) << " ";
		system("cls");
		cout << setw(36) << " " << endl;;
		MainScreen();
	}

	




};

