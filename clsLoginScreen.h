#pragma once
#include<iostream>
#include"clsUsers.h"
#include"clsMainBar.h"
#include"clsScreen.h"
#include"Globail.h"

class clsLoginScreen:clsMainBar
{
	static void _Login() {
		bool loginFaild = false;
		string UserName, Passward;
		int TrialCOunter = 0;
		do {
			_DrawScreenHedaer("Login Screen ");
			if (loginFaild) {
				cout << setw(36) << " " << "InValid UserName /Passward" << endl;
				cout << "You have [" << 3 - TrialCOunter << "]To Login" << endl;;
			}
			cout << setw(36) << " " << "Enter UserName ?" << endl;
			getline(cin >> ws, UserName);

			cout << setw(36) << " " << "Enter Passward ?" << endl;
			getline(cin, Passward);
			CurrentUser = clsUser::Find(UserName,Passward);
			loginFaild = CurrentUser.IsEmpty();
			TrialCOunter++;
			if (TrialCOunter == 3) {
				Failed = true;
				return;
			}
			system("cls");
		} while (loginFaild);
		CurrentUser.RegisterLogin();
		clsScreen::MainScreen();

	}



public :
	static void ShowLoginScreen() {
		system("cls");
	
		_Login();


	}


};

