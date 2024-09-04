#include <iostream>
#include "clsPerson.h"
#include "clsBankClient.h"
#include<iostream>
#include"clsScreen.h"
#include"clsLoginScreen.h"
#include"Globail.h"
using namespace std;
int main()
{
    
    while (true) {
        clsLoginScreen::ShowLoginScreen();
        if (Failed == true) {
            return 0;
        }
    }
    system("cls");


    system("pause>0");
    return 0;
}