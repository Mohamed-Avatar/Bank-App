#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsValidate.h"
#include<iomanip>
#include"Globail.h"
#include"clsDate.h"
using namespace std;
class clsMainBar
{
protected:
	static void _DrawScreenHedaer(string Title,string SubTitle="") {
		cout << endl;
		cout << setw(36) << " " << "------------------------------------" << endl;
		cout << setw(36) << " " << "            "<<Title<<"           " << endl;
		cout << setw(36) << " " << "-----------------------------------" << endl;
		if (SubTitle != "") {
			cout << setw(36) << " " << "            " << SubTitle << "           " << endl;
			cout << setw(36) << " " << "-----------------------------------" << endl;
		}
		cout << setw(36) << " " << "User " << CurrentUser.UserName << endl;

		cout << setw(36) << " " << "Date " << clsDate::DateToString(clsDate()) << endl;
		cout << setw(36) << " " << "-----------------------------------" << endl;

		cout << endl;
		

	}
	static bool ShowAcsessRight(clsUser::enPermission Permission) {
		if (!CurrentUser.CheckAcsessPermission(Permission)) {
			cout << setw(36) << " " << "------------------------------------" << endl;
			cout << setw(36) << " " << "            " << "Acsess Deniy " << "           " << endl;
			cout << setw(36) << " " << "-----------------------------------" << endl;
			return false;
		}
		else {
			return true;
		}
	}



};

