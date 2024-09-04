#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsValidate.h"
#include"clsScreen.h"
#include<iomanip>
class clsClientListScreen :protected clsMainBar
{
    static void PrintClientRecordLine(clsBankClient Client)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FirstName+" "+Client.LastName;
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }
public:
	static void ShowClientsList() {
		vector<clsBankClient>vClients = clsBankClient::GetClientsList();
		string Title = "Show All Aclients List Screen ";
		string SubTitle = (to_string(vClients.size()));
		_DrawScreenHedaer(Title, SubTitle);

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        if (vClients.size() == 0) {
            cout << "\t\t\t\t No Clients Avalible " << endl;
        }
        else {

            for (clsBankClient C : vClients) {


                PrintClientRecordLine(C);
                cout << endl;

            }
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;






        }
	}




};

