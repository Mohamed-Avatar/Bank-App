#pragma once
#include"clsUsers.h"
#include"clsMainBar.h"
#include<iostream>
class clsFindUserScreen:clsMainBar
{
public:
    static void ShowFindScreen() {
        system("cls");
        string Title = "Show Find User Screen ";
        _DrawScreenHedaer(Title);
        string UserName = "";
        cout << setw(36) << " " << "Please Enter Your User Name  ?" << endl;
        getline(cin >> ws, UserName);
        while (!clsUser::IsUserExist(UserName)) {

            cout << setw(36) << " " << "Wrong ,User Nameis Not  Exist ." << endl;
            UserName = "";
            cout << setw(36) << " " << "Please Enter Your User Name ?" << endl;
            getline(cin >> ws, UserName);

        }
        clsUser Obj = clsUser::Find(UserName);
        Obj.Print();






    }





};

