#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include"Globail.h"
#include"clsMainBar.h"
#include <vector>
#include <fstream>

class clsShowTransferScreen:clsMainBar
{
    static void PrintTransfersRecordLine(clsUser::stLoginTransfer Logins)
    {

        cout << setw(8) << left << "" << "| " << setw(25) << left << Logins.Date;
        cout << "| " << setw(12) << left << Logins.AccNo_From;
        cout << "| " << setw(12) << left << Logins.AccNo_To;
        cout << "| " << setw(12) << left << Logins.Amount;
        cout << "| " << setw(32) << left << Logins.Balnce_After;
        cout << "| " << setw(12) << left << Logins.User_userName << endl;;
    }

public:
    static void ShowTransferList() {
        vector<clsUser::stLoginTransfer>vClients = clsUser::GetLoginTransfersList();
        string Title = "Show All Users List Screen ";
        string SubTitle = (to_string(vClients.size()));
        _DrawScreenHedaer(Title, SubTitle);

        cout << setw(8) << left << "" << "| " << setw(25) << left <<"Date ";
        cout << "| " << setw(12) << left << "From Account ";
        cout << "| " << setw(12) << left <<"To Account ";
        cout << "| " << setw(12) << left << "Amount ";
        cout << "| " << setw(32) << left << "Blance Before Transaction";
        cout << "| " << setw(12) << left <<"User ";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        if (vClients.size() == 0) {
            cout << "\t\t\t\t No Clients Avalible " << endl;
        }
        else {

            for (clsUser::stLoginTransfer &C : vClients) {


                PrintTransfersRecordLine(C);
      

            }
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;






        }
    }
};

