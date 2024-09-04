#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsValidate.h"
#include"clsMainBar.h"
#include"clsListUsersScreen.h"
#include"clsAddNewUsersScreen.h"
#include"clsFindUserScreen.h"
#include"UpdateUserScreen.h"
#include<iomanip>
#include"clsDeleteUsersScreen.h"
class clsMangeUsersScreen:clsMainBar
{






	enum enMangeUsersOption { ListUsers=1,AddNewUsers = 2, DeleteUsers = 3, UpdateUsers = 4, FindUsers = 5,MainMenu=6 };
	static void _PerformeTransactionoption(enMangeUsersOption Ch) {
		switch (Ch)
		{
		case clsMangeUsersScreen::ListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoBackTOMangeUsersManu();
			break;
		case clsMangeUsersScreen::AddNewUsers:
			system("cls");
			_ShowAddNewUsersScreen();
			_GoBackTOMangeUsersManu();
			break;
		case clsMangeUsersScreen::DeleteUsers:
			system("cls");
			_ShowDeleteUsersScreen();
			_GoBackTOMangeUsersManu();
			break;
		case clsMangeUsersScreen::UpdateUsers:
			system("cls");
			_ShowUpdateUsersScreen();
			_GoBackTOMangeUsersManu();
			break;
		case clsMangeUsersScreen::FindUsers:
			system("cls");
			_ShowFindUsersScreen();
			_GoBackTOMangeUsersManu();
			break;
		case clsMangeUsersScreen::MainMenu:
		

			break;
		}
	}
	static void _ReadTransactionMenu() {
		int Choice = 0;
		Choice = clsInputValidate::ReadIntNumberBetween(1, 6);
		_PerformeTransactionoption((enMangeUsersOption)Choice);



	}

	static void _ShowListUsersScreen() {
		clsUsersListScreen::ShowUsersList();
	}
	static void _ShowAddNewUsersScreen() {
		clsAddNewUserScreen::ShowAddNewClientScreen();
	}
	static void _ShowDeleteUsersScreen() {
		clsDeleteUsersScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUsersScreen() {
		UpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUsersScreen() {
		clsFindUserScreen::ShowFindScreen();
	}

public:
	static void MangeUsersScreen() {
		system("cls");
		_DrawScreenHedaer("MangeUsers  Screen");
		cout << setw(36) << " " << "[1] ListUsers Users " << endl;
		cout << setw(36) << " " << "[2] Add New Users " << endl;
		cout << setw(36) << " " << "[3] Delete User  " << endl;
		cout << setw(36) << " " << "[4] Update  Users  " << endl;
		cout << setw(36) << " " << "[5]Find Users " << endl;
		cout << setw(36) << " " << "[6]Go Back MainMenu " << endl;

		cout << setw(36) << " " << "==============================================" << endl;
		cout << setw(36) << " " << "Enter Your Choices [1 to 5]? " << endl;
		_ReadTransactionMenu();
	}





	static void _GoBackTOMangeUsersManu() {

		cout << endl;
		cout << setw(36) << " " << "Press any Key To Go Back Mange Users Menu ...." << endl;
		cout << setw(36) << " ";
		system("Pause>0");
		cout << setw(36) << " ";
		system("cls");
		cout << setw(36) << " " << endl;;
		MangeUsersScreen();

	}





};

