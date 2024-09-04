#pragma once
#include"clsUsers.h"
#include"clsMainBar.h"
#include"clsAddNewUsersScreen.h"
#include<iostream>

class UpdateUserScreen:clsMainBar
{

	static void  _ReadUser(clsUser& User)
	{
		
		User.FirstName = clsInputValidate::ReadString("Enter First Name ?");

		User.LastName = clsInputValidate::ReadString("Enter Last Name ?");

		User.Email = clsInputValidate::ReadString("Enter Email ?");


		User.Phone = clsInputValidate::ReadString("Enter  Phone ?");


		User.UserName = clsInputValidate::ReadString("Enter UserName  ?");
		User.Password = clsInputValidate::ReadString("Enter PassWard  ?");
		cout << setw(36) << " " << "Enter Permission  ?";

		User.Permissions = clsAddNewUserScreen::_ReadPermissionTOSet();


	}

public:
	static void ShowUpdateUserScreen() {
		string Title = "Update Client Screen ";
		_DrawScreenHedaer(Title);
		string username = clsInputValidate::ReadString("Enter  UserName ?");
		while (!clsUser::IsUserExist(username)) {
			cout << setw(36) << " " << "Wrong ,User is already Exist ." << endl;
			username = "";

			username = clsInputValidate::ReadString("Enter User Name   ?");


		}
		clsUser Obj = clsUser::Find(username);
		Obj.Print();
		char An = 'n';
		cout << setw(36) << " " << "Are you sure do you want to update this User [Y/N]?" << endl;
		cout << setw(36) << " ";
		cin >> An;

		if (toupper(An) == 'Y') {
			clsUser::enSaveResults SaveResult;
			_ReadUser(Obj);
			SaveResult = Obj.Save();

		}
		else {

			cout << setw(36) << " " << "User Not Updated " << endl;

		}


	}

};

