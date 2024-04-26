//*****************************//
//		  Assignment #2        //
//     Student: Cooper Wolf    //
//		  Date: 3/3/23         //
//************************************************//
//	 This program acts as a data base for a bank  //
//   This program includes classes and functions  //
//   that can increase/decrease the amount of     //
//   money in a persons savings or checking       //
//   account. This program runs by building       //
//   solution and clicking local windows debugger //
//   the names of the files used in this program  //
//   are Account.h and Account.cpp. One stores    //
//   the classes used in this program and the     //
//   other includes the fuctions used in the      //
//   classes.                                     //                             
//                                                //
//************************************************//
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <istream>
#include "Account.h"
using namespace std;

int main()
{
    int answer;
    string keepgoing = "yes";
    account bank(keepgoing);
    bank.setdata();
    while (keepgoing == "Yes" || keepgoing == "yes")
    {
        cout << "\n\nWhat else would you like to do?(enter number) \n";
        cout << "1.Deposit.\n";
        cout << "2.Withdraw\n";
        cout << "3.Transfer money between accounts.\n";
        cout << "4.Transfer money between clients.\n";
        cout << "5.See all bank data.\n";
        cout << "6.Nothing.\n";
        cin >> answer;
        switch (answer)
        {
        case 1:
            bank.increase();
            break;
        case 2:
            bank.decrease();
            break;
        case 3:
            bank.transferwithin();
            break;
        case 4:
            bank.transferoutside();
            break;
        case 5: 
            bank.printdata();
        
        }
        if(answer == 6)
          break;
    }
}