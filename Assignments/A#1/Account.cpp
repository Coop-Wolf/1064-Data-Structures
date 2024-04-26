#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "Account.h"
using namespace std;

//****************************************************//
//              Function Name: date                   //
// Member Function of date and it is a constructor    //
// This has no parameter. This function sets all the  //
// variables to zero. This function does not return   //
// any value.                                         //
//****************************************************//

date::date()
{
    year = 0;
    month = 0;
    day = 0;
}

//****************************************************//
//              Function Name: setdate                //
//              Inpute Parameters: int d,m,y          //
// Member Function of date. This function receices    //
// Integers values and sets them to day, month, year  //
//                                                    //
//****************************************************//


void date::setdate(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

//****************************************************//
//              Function Name: getdate                //
//              Input Parameters: Zero                //
// Member Function of date. This function prints      //
// out the day, month, and year that was previously   //
// entered in by the user                             //
//****************************************************//

void date::getdate()
{
    cout << day << "/" << month << "/" << year;
}

//****************************************************//
//              Function Name: account                //
// Member function of account and it is a constructor //
// with a parameter. If used, this fuction creates 50 //
// vectors of 4 different data types and initializes  //
// all values to zero/unknown.                        //
// ***************************************************//

account::account(string answer)

{
    vector<long> accountnumber(0, 50);
    vector<char> accounttype(0, 50);
    vector<string> name(0, "Unknown");
    vector<double> balance(0, 50);
}

//****************************************************//
//              Function Name: ~account               //
// Member function of account. No input parameters    //
// This function is a deconstructor and prints out    //
// a message before the class is destroyed            //
//****************************************************//

account::~account()
{
    cout << "\nHave a good rest of the day!\n";
}

//****************************************************//
//              Function Name: setdata                //
// Member function of account. No input parameters    //
// This function allows the user to input bank        //
// accounts. It has a white loop that asks the user   //
// if they would like to continue entering in accounts//
// does not return any vaule.                         //
//****************************************************//

void account::setdata()
{
    string answer = "yes";
    cout << "Begin entering account information below.\n";
    cout << endl;
    while (answer == "yes" || answer == "Yes")
    {
        string names;
        double account;
        double accountnum;
        char acctype;
        int d, m, y;
        cout << "Name: ";
        cin >> names;
        name.push_back(names);
        cout << "Account number: ";
        cin >> accountnum;
        accountnumber.push_back(accountnum);
        cout << "Checking or Savings account (s or c): ";
        cin >> acctype;
        accounttype.push_back(acctype);
        cout << "Balance: $";
        cin >> account;
        balance.push_back(account);
        count++;
        cout << endl;
        cout << "Would you like to enter more information? ";
        cin >> answer;
        cout << endl;
    }
}

//****************************************************//
//              Function Name: Printdata              //
// Member function of account. No input parameters    //
// This function prints out all of the information    //
// that the user previously inputed. This function    //
// does not return any vaule.                         //
//****************************************************//

void account::printdata()
{
    cout << "This is our data base information.\n";
    for (int i = 0; i < count; i++)
    {
        cout << endl << "Name: " << name[i];
        cout << endl << "Account Number: " << accountnumber[i];
        cout << endl << "Account Type: " << accounttype[i];
        cout << fixed << setprecision(2) << endl << "Balance: $" << balance[i];
        cout << "\n\n";
    }
}

//****************************************************//
//              Function Name: Increase               //
// Member function of account. No input parameters    //
// This function deposits money into an account chosen//
// by the user. This function returns a new balance   //
// for the given account.                             //
//****************************************************//

void account::increase()
{
    int d;
    int m;
    int y;
    double number;
    double money;
    string name;
    char a;
    cout << "Who's account would you like to deposit money into? ";
    cin >> name;
    cout << "Savings or Checking (s or c)? ";
    cin >> a;
    cout << "Account number: ";
    cin >> number;
    cout << "Amount: $";
    cin >> money;
    cout << "Date: ";
    cin >> d;
    cin >> m;
    cin >> y;
    date_of_last_payment.setdate(d, m, y);
    cout << endl;
    int searchResult(vector<double>accountnumer, double number);
    int num = 0;
    for (int i = 0; i < accountnumber.size(); i++) {
        if (accountnumber[i] == number) {
            num = i;
        }
    }
    balance[num] += money;
    cout << "\nUpdated Account";
    cout << endl << "Name: " << name;
    cout << endl << "Account Number: " << accountnumber[num];
    cout << endl << "Account Type: " << accounttype[num];
    cout << fixed << setprecision(2) << endl << "New Balance: $" << balance[num];
    cout << endl << "Date of last payment: ";
    date_of_last_payment.getdate();
}

//****************************************************//
//              Function Name: Decrease               //
// Member function of account. No input parameters    //
// This function withdraws money from an account      //
// chosen by the user. This function returns a new    //
// balance for the given account.                     //
//****************************************************//

void account::decrease()
{
    int d;
    int m;
    int y;
    double number;
    double money;
    string name;
    char a;
    cout << "Who's account would you like to withdraw money from? ";
    cin >> name;
    cout << "Saving or Checking (s or c)? ";
    cin >> a;
    cout << "Account number: ";
    cin >> number;
    cout << "Amount: $";
    cin >> money;
    cout << "Date: ";
    cin >> d;
    cin >> m;
    cin >> y;
    date_of_last_payment.setdate(d, m, y);
    int searchResult(vector<double>accountnumer, double number);
    int num = 0;
    for (int i = 0; i < accountnumber.size(); i++) {
        if (accountnumber[i] == number) {
            num = i;
        }
    }
    balance[num] -= money;
    cout << "\nUpdated Account";
    cout << endl << "Name: " << name;
    cout << endl << "Account Number: " << accountnumber[num];
    cout << endl << "Account Type: " << accounttype[num];
    cout << fixed << setprecision(2) << endl << "New Balance: $" << balance[num];
    cout << endl << "Date of last payment: ";
    date_of_last_payment.getdate();
}

//****************************************************//
//              Function Name: transferwithin         //
// Member function of account. No input parameters    //
// This function transfers money within a persons     // 
// account. Either savings to checking or vise versa  //
// by the user. This function returns a new balance   //
// for the two account used.                          //
//****************************************************//

void account::transferwithin()
{
    int d;
    int m;
    int y;
    double number2;
    double number;
    double money;
    string name;
    int num = 0;
    int num2 = 0;
    int a;
    cout << "Who's account would you like to use to transfer money? ";
    cin >> name;
    cout << "Checking account number: ";
    cin >> number;
    cout << "Savings account number: ";
    cin >> number2;
    cout << "\nHow would you like to transfer the funds?";
    cout << "\n1.Saving to Checking.\n";
    cout << "2.Checking to Saving.\n";
    cin >> a;
    cout << "Amount: $";
    cin >> money;
    cout << "Date: ";
    cin >> d;
    cin >> m;
    cin >> y;
    date_of_last_payment.setdate(d, m, y);
    cout << endl;
    int searchResult(vector<double>accountnumer, double number);
    for (int i = 0; i < accountnumber.size(); i++) {
        if (accountnumber[i] == number) {
            num = i;
        }
    }
    int searchResult(vector<double>accountnumer, double number2);
    for (int j = 0; j < accountnumber.size(); j++) {
        if (accountnumber[j] == number2) {
            num2 = j;
        }
    }
    if (a == 1)
    {
        balance[num2] -= money;
        balance[num] += money;
    }
    else
    {
        balance[num2] += money;
        balance[num] -= money;
    }
    cout << "\nUpdated Accounts";
    cout << endl << "Name: " << name;
    cout << endl << "Account Number: " << accountnumber[num];
    cout << endl << "Account Type: " << accounttype[num];
    cout << fixed << setprecision(2) << endl << "New Balance: $" << balance[num];
    cout << endl << "Date of last payment: ";
    date_of_last_payment.getdate();
    cout << endl;
    cout << endl << "Name: " << name;
    cout << endl << "Account Number: " << accountnumber[num2];
    cout << endl << "Account Type: " << accounttype[num2];
    cout << fixed << setprecision(2) << endl << "New Balance: $" << balance[num2];
    cout << endl << "Date of last payment: ";
    date_of_last_payment.getdate();
}

//****************************************************//
//              Function Name: transferoutside        //
// Member function of account. No input parameters    //
// This function transfers money from one person to   //
// another by either accounts (checking or savings)   // 
// This function returns the new balance              //
// for the two accounts used in the trasnaction       //
//****************************************************//

void account::transferoutside()
{
    int d;
    int m;
    int y;
    double number;
    double number2;
    double money;
    string name;
    string name2;
    int num = 0;
    int num2 = 0;
    int a;
    cout << "Name of account you would like to transfer money from: ";
    cin >> name;
    cout << "Name of account you would like to transfer money to: ";
    cin >> name2;
    cout << "\nHow would you like to transfer the funds? ";
    cout << "\n1.Saving to Saving.";
    cout << "\n2.Checking to Checking.";
    cout << "\n3.Saving to Checking.";
    cout << "\n4.Checking to Saving.\n";
    cin >> a;
    cout << "\nAccount number for " << name << " : ";
    cin >> number;
    cout << "Account number for " << name2 << " : ";
    cin >> number2;
    cout << "Amount: $";
    cin >> money;
    cout << "Date: ";
    cin >> d;
    cin >> m;
    cin >> y;
    date_of_last_payment.setdate(d, m, y);
    cout << endl;
    int searchResult(vector<double>accountnumer, double number);
    for (int i = 0; i < accountnumber.size(); i++) {
        if (accountnumber[i] == number) {
            num = i;
        }
    }
    int searchResult(vector<double>accountnumer, double number2);
    for (int j = 0; j < accountnumber.size(); j++) {
        if (accountnumber[j] == number2) {
            num2 = j;
        }
    }
    balance[num2] += money;
    balance[num] -= money;
    cout << "\nUpdated Accounts";
    cout << endl << "Name: " << name;
    cout << endl << "Account Number: " << accountnumber[num];
    cout << endl << "Account Type: " << accounttype[num];
    cout << fixed << setprecision(2) << endl << "New Balance: $" << balance[num];
    cout << endl << "Date of last Payment: ";
    date_of_last_payment.getdate();
    cout << endl;
    cout << endl << "Name: " << name2;
    cout << endl << "Account Number: " << accountnumber[num2];
    cout << endl << "Account Type: " << accounttype[num2];
    cout << fixed << setprecision(2) << endl << "New Balance: $" << balance[num2];
    cout << endl << "Date of last payment: ";
    date_of_last_payment.getdate();
}
