
#pragma once
#include<iostream>
#include<iomanip>
#include"clsMainBar.h"
#include"clsString.h"
#include"clsBankClient.h"
#include"clsUsers.h"
#include"clsDate.h"
#include"Globail.h"
using namespace std;
class clsTransFerLogs
{
    static string _GenrateLine(clsBankClient Source, clsBankClient Denstin, double Amount) {
        string Line;
        clsDate Date;

        Line += clsDate::GetSystemTimeDateString() + "#//#";
        Line +=Source.AccountNumber()+"#//#";
        Line += (Denstin.AccountNumber())+"#//#";
        Line += to_string(Amount) + "#//#";
        Line += to_string(Source.AccountBalance) + "#//#";
        Line += CurrentUser.UserName ;
        return Line;




    }
public :
    static void RegisterTransfer(clsBankClient Source, clsBankClient Denstin, double Amount) {
        string stDateLine = _GenrateLine(Source, Denstin, Amount);
        fstream MyFile;
        MyFile.open("TransferLogs.txt", ios::app | ios::out);
        if (MyFile.is_open()) {

            MyFile << stDateLine << endl;




        }
        MyFile.close();



    }

};

