#pragma once
#include<iostream>
#include<iomanip>
#include"clsMainBar.h"
#include"clsString.h"
#include"clsUsers.h"
using namespace std;
class clsLoginsScreen:clsMainBar
{
    static void PrintUserRecordLine(clsUser::stLoginScreen Logins)
    {

        cout << setw(8) << left << "" << "| " << setw(40) << left << Logins.Date;
        cout << "| " << setw(20) << left << Logins.UserName ;
        cout << "| " << setw(12) << left << Logins.Passwor;
        cout << "| " << setw(12) << left << Logins.Permission;

    }

public:
    static void ShowUsersList() {
        vector<clsUser::stLoginScreen>vClients = clsUser::GetLoginRegistureList();
        string Title = "Show All Users List Screen ";
        string SubTitle = (to_string(vClients.size()));
        _DrawScreenHedaer(Title, SubTitle);

        cout << setw(8) << left << "" << "| " << left << setw(40) << "Date ";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(12) << "Passward";
        cout << "| " << left << setw(12) << "Peemission";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        if (vClients.size() == 0) {
            cout << "\t\t\t\t No Clients Avalible " << endl;
        }
        else {

            for (clsUser::stLoginScreen C : vClients) {


                PrintUserRecordLine(C);
                cout << endl;

            }
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;






        }
    }
};

