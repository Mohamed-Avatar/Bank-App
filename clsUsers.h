#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include"Globail.h"
#include"clsUtil.h"
#include <vector>
#include <fstream>
#include"clsValidate.h"
using namespace std;
class clsUser : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;

    bool _MarkedForDelete = false;

    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], (vUserData[5]), stoi(vUserData[6]));

    }


    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {
        
        string UserRecord = "";
        UserRecord += User.FirstName + Seperator;
        UserRecord += User.LastName + Seperator;
        UserRecord += User.Email + Seperator;
        UserRecord += User.Phone + Seperator;
        UserRecord += User.UserName + Seperator;
        UserRecord += (User.Password)+ Seperator;
        UserRecord += to_string(User.Permissions);

        return UserRecord;

    }

    static  vector <clsUser> _LoadUsersDataFromFile()
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users2.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("Users2.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users2.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
     string _GenrateLine() {
        string Line;
        clsDate Date;

        Line += clsDate::GetSystemTimeDateString() + "#//#";
        Line += (UserName) + "#//#";
        Line +=Password + "#//#";
        Line += to_string(Permissions);
        return Line;




    }

public:
    struct stLoginScreen {
        string Date;
        string UserName;
        string Passwor;
        string Permission;
    };
    struct stLoginTransfer {
        string Date;
        string AccNo_From;
        string AccNo_To;
        double  Amount;
        double  Balnce_After;
        string User_userName;
    };
    clsUser(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password,
        int Permissions) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string GetUserName()
    {
        return _UserName;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users2.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("Users2.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName && User.Password == User.Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNew();
                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }

    }

    static bool IsUserExist(string UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    void Print()
    {
        cout << endl;
        cout << setw(36) << " " << "\nUser Card:";
        cout << setw(36) << " " << "\n___________________";
        cout << setw(36) << " " << "\nFirstName   : " << FirstName;
        cout << setw(36) << " " << "\nLastName    : " << LastName;
        cout << setw(36) << " " << "\nFull Name   : " << FirstName + " " + LastName;
        cout << setw(36) << " " << "\nEmail       : " << Email;
        cout << setw(36) << " " << "\nPhone       : " << Phone;
        cout << setw(36) << " " << "\nUserName: " << UserName;
        cout << setw(36) << " " << "\nPassword    : " << Password;
        cout << setw(36) << " " << "\Permission     : " << Permissions;
        cout << endl;

    }
    enum enPermission {
        pAll = -1, pListCLient = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUdateClient = 8, pFindCLient = 16, pTreansactionMenu = 32, pMangeUsers = 64,pLoginsScreen=128,
    pCurrencyEcxhange=256
    };
    bool CheckAcsessPermission(enPermission Permission) {
        if (this->Permissions == enPermission::pAll) {
            return true;

        }
        if ((this->Permissions &Permission)== Permission) {
            return true ;

        }
        else {
            return false;
        }
    }
    
public:
     void RegisterLogin() {
         string stDateLine = _GenrateLine();
        fstream MyFile;
        MyFile.open("LoginsFile.txt", ios::app|ios::out);
        if (MyFile.is_open()) {

            MyFile << stDateLine << endl;




        }
        MyFile.close();



     }

     static stLoginScreen _ConvertLinetoLOginObject(string Line, string Seperator = "#//#")
     {
         stLoginScreen LoginScreenObj;

         vector <string>vLogins;
         vLogins = clsString::Split(Line,Seperator);
         LoginScreenObj.Date = vLogins[0];
         LoginScreenObj.UserName = vLogins[1]; 
         LoginScreenObj.Passwor =(vLogins[2]); 
         LoginScreenObj.Permission = vLogins[3];
         return LoginScreenObj;
     }
     static  vector <stLoginScreen> GetLoginRegistureList()
     {

         vector <stLoginScreen>vLoLogin;
         stLoginScreen LoginScreenObj;
         fstream MyFile;
         MyFile.open("LoginsFile.txt", ios::in);//read Mode

         if (MyFile.is_open())
         {

             string Line;


             while (getline(MyFile, Line))
             {

                 LoginScreenObj = _ConvertLinetoLOginObject(Line);

                 vLoLogin.push_back(LoginScreenObj);
             }

             MyFile.close();

         }

         return vLoLogin;

     }
     static clsUser::stLoginTransfer _ConvertLinetoTransfersObject(string Line, string Seperator = "#//#")
     {
         clsUser::stLoginTransfer LoginScreenObj;

         vector <string>vLogins;
         vLogins = clsString::Split(Line, Seperator);
         LoginScreenObj.Date = vLogins[0];
         LoginScreenObj.AccNo_From = vLogins[1];
         LoginScreenObj.AccNo_To = vLogins[2];
         LoginScreenObj.Amount = stod(vLogins[3]);
         LoginScreenObj.Balnce_After = stod(vLogins[4]);
         LoginScreenObj.User_userName = vLogins[5];
         return LoginScreenObj;
     }
     static  vector <clsUser::stLoginTransfer > GetLoginTransfersList()
     {
         
         vector <clsUser::stLoginTransfer >vLoLogin;
         clsUser::stLoginTransfer  LoginScreenObj;
         fstream MyFile;
         MyFile.open("TransferLogs.txt", ios::in);//read Mode

         if (MyFile.is_open())
         {

             string Line;


             while (getline(MyFile, Line))
             {

                 LoginScreenObj = _ConvertLinetoTransfersObject(Line);

                 vLoLogin.push_back(LoginScreenObj);
             }

             MyFile.close();

         }

         return vLoLogin;

     }
     

     
};



