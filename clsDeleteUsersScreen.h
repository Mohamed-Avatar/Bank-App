#pragma once
#include<iostream>
#include"clsMainBar.h"
#include"clsUsers.h"
class clsDeleteUsersScreen:clsMainBar
{
public:
	static void ShowDeleteUserScreen() {
		string Title = "Delete  User Screen ";
		_DrawScreenHedaer(Title);
		string username = clsInputValidate::ReadString("Enter UserName ?");
		while (!clsUser::IsUserExist(username)) {
			cout << setw(36) << " " << "Wrong ,UserName is already Exist ." << endl;
			username = "";

			username = clsInputValidate::ReadString("Enter UserName ?");


		}
		clsUser Obj = clsUser::Find(username);
		Obj.Print();
		char An = 'n';
		cout << setw(36) << " " << "Are you sure do you want to Delete  this client [Y/N]?" << endl;
		cout << setw(36) << " ";cin >> An;

		if (toupper(An) == 'Y') {

			Obj.Delete();
			Obj.Print();

		}
		else {

			cout << setw(36) << " " << "Client Not Deleted " << endl;

		}
	}

};

