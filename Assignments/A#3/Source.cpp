//************************************************//
//                                                //
//			    Assignment #5                     //
//				Name:	Cooper Wolf               //
//				Class:	Data Structures			  //
//				Date:	4/22/23					  //	
// 												  //	
//************************************************//
//                                                //  
//         This program uses recursion to         //  
//         for calulate two problems. The         // 
//         program first asks for a single        //
//         integer and prints the summation       //
//         of odd integers between 1 and          //   
//         the number given by the user.          //
//         The second functions asks the user     //
//         for two number (base,exponent) and     //
//         calculates the result. This program    //
//         is ran by clicking build, build        //
//         solution, and Local Windows Debugger.  //
//                                                //
//************************************************//          

#include <iostream>
#include <cmath>
using namespace std;

//Function prototypes//
long double Summation( long double num);
double BaseExponent(long base, long xpo);

//beginning program//
int main()
{
    long double num;
    long x, y;
    cout << "===================================================\n\n";
    cout << "Enter an integer to calculate the summation: ";
    cin >> num;
    cout << "The summation of all odd numbers \n";
    cout << "between 1 and " << num << " is " << Summation(num) << "\n\n";
    cout << "===================================================\n\n";
    cout << "Enter two integers to calculate exponents: ";
    cout << "\nBase: ";
    cin >> x;
    cout << "Exponent: ";
    cin >> y;
    cout << x << "^" << y << " = " << BaseExponent(x, y);
    cout << "\n\n===================================================";
}

//************************************************//
//                                                //
//            Function name: Summation            //  
//   Function parameters: long double num         //  
//                                                //
//************************************************//
//                                                //  
//         This function is passed a value        //
//         and if that value is even, it          // 
//         subtracts it by one. It then goes      //
//         through and decides if its less than   //
//         zero. If so it returns a zero. If not  //
//         it goes about through the functions    //
//         with the value being decremented by 2  //
//         until the value is less than zero.     //
//                                                //
//************************************************//

long double Summation(long double num)
{
    if (fmod(num,2) == 0)
        num -= 1;
    if (num < 0)
        return 0;
    else
        return num + Summation(num - 2);
}

//************************************************//
//                                                //
//            Function name: BaseExponent         //  
//       Function parameters: long num, long xpo  //  
//                                                //
//************************************************//
//                                                //  
//         This function is passed two values     //
//         int the form of base and exponent      //
//         the function then uses recursion to    //
//         calculate the result of a given value  //
//         raised to a given value.               //
//                                                //
//************************************************//

double BaseExponent(long base, long xpo)
{
    if (xpo < 1)
        return 1;
    else
        return base * BaseExponent(base, xpo - 1);
}