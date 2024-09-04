#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsValidate.h"
#include"clsScreen.h"
#include"clsUsers.h"
#include<iomanip>
class clsUsersListScreen :protected clsMainBar
{
    static void PrintUserRecordLine(clsUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << User.UserName;
        cout << "| " << setw(20) << left << User.FirstName + " " + User.LastName;
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;

    }
public:
    static void ShowUsersList() {
        vector<clsUser>vClients = clsUser::GetUsersList();
        string Title = "Show All Users List Screen ";
        string SubTitle = (to_string(vClients.size()));
        _DrawScreenHedaer(Title, SubTitle);

        cout << setw(8) << left << "" << "| " << left << setw(15) << "UserName";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "PassWard";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        if (vClients.size() == 0) {
            cout << "\t\t\t\t No Clients Avalible " << endl;
        }
        else {

            for (clsUser C : vClients) {


                PrintUserRecordLine(C);
                cout << endl;

            }
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;






        }
    }




};

