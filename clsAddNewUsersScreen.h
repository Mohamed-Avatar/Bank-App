#pragma once
#include<iostream>
#include"clsUsers.h"
#include"clsValidate.h"
#include"clsScreen.h"
#include<iomanip>
using namespace std;
class clsAddNewUserScreen :clsMainBar
{
private:
    static void PrintUserRecordLine(clsUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << User.UserName;
        cout << "| " << setw(20) << left << User.FirstName + " " + User.LastName;
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;

    }
    static void  _ReadClient(clsUser& Client)
    {

        Client.FirstName = clsInputValidate::ReadString("Enter First Name ?");

        Client.LastName = clsInputValidate::ReadString("Enter Last Name ?");
 
        Client.Email = clsInputValidate::ReadString("Enter Email ?");


        Client.Phone = clsInputValidate::ReadString("Enter  Phone ?");




        Client.Password = clsInputValidate::ReadString("Enter Passward ?");
        cout << setw(36) << " " << "Enter  Enter Permission ?";

        Client.Permissions = _ReadPermissionTOSet();


    }
   




public:
    static int _ReadPermissionTOSet() {
        int Permission = 0;
        char Answer = 'n';
        cout << setw(36) << " " << "Do yu want to give full access " << endl;
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            return -1;
        }
        cout << setw(36) << " " << "Do yu want to give ListUsers access " << endl;
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            Permission += clsUser::pListCLient;
        }
        cout << setw(36) << " " << "Do yu want to give Add New Users access " << endl;
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            Permission += clsUser::pAddNewClient;
        }
        cout << setw(36) << " " << "Do yu want to give Delete Users access " << endl;
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            Permission += clsUser::pDeleteClient;
        }
        cout << setw(36) << " " << "Do yu want to give Update Users access " << endl;
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            Permission += clsUser::pUdateClient;
        }
        cout << setw(36) << " " << "Do yu want to give Find Users access " << endl;
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            Permission += clsUser::pFindCLient;
        }
        cout << setw(36) << " " << "Do yu want to give TransactionMenu access " << endl;
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            Permission += clsUser::pTreansactionMenu;
        }
        cout << setw(36) << " " << "Do yu want to give MangeUser access " << endl;
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            Permission += clsUser::pMangeUsers;
        }
        cout << setw(36) << " " << "Do yu want to give Add LoginsScreen access " << endl;
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            Permission += clsUser::pLoginsScreen;
        }
        return Permission;
    }
    static void ShowAddNewClientScreen() {
        system("cls");
        cout << endl;
        _DrawScreenHedaer("Adding New User Screen ");
        string userName = "";
        cout << setw(36) << " " << "Please Enter Your userName ?" << endl;
        getline(cin >> ws, userName);
        while (clsUser::IsUserExist(userName)) {

            cout << setw(36) << " " << "Wrong ,UserName is already Exist ." << endl;
            userName = "";
            cout << setw(36) << " " << "Please Enter Your userName ?" << endl;
            getline(cin >> ws, userName);





        }
        clsUser NewClient = clsUser::GetAddNewUserObject(userName);
        _ReadClient(NewClient);
        clsUser::enSaveResults SaveResult;
        SaveResult = NewClient.Save();
        switch (SaveResult)
        {
        case clsBankClient::svFaildEmptyObject:
            cout << "We Cant Storage This Obj " << endl;
            break;
        case clsBankClient::svSucceeded:
            cout << "User Adding Asuccessfuly " << endl;
            break;
        case clsBankClient::svFaildAccountNumberExists:
            cout << "We Cant Storage This Obj,UaserName Number Is Exist " << endl;
            break;
        default:
            break;
        }
    }






};


