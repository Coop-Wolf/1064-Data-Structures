//*******************************************//
//                                           //
//             Assignment #4                 //
//             Name: Cooper Wolf             //
//             Date Structures               //
//             Date:  4/6/23                 //
//*******************************************//
//     This program creates a dynamically    //
//     allocated 2d array array with         //
//     dimensions determined by the user     //
//     The program then generates random     //
//     numbers from 1000 to 5999 that        //
//     symbolize the social security # of    //
//     people. The program then goes through //
//     various functions. One prints out the // 
//     matrix of random numbers while        //
//     another determines weather the        //
//     numbers of SSN in the 1000's          //
//     2000's and so on. Another function    //
//     prints out the number of male and     //
//     female according to the SSN's. This   //
//     program runs by clicking build, build //
//     solutions then clicking Local Windows //
//     Debugger.                             //
//                                           //
//*******************************************//


#include <iostream>
using namespace std;

void fillnprint(int, int, int**);
void SSN(int, int, int**, int);
void genders(int, int, int**, int);

int main()
{
  int row, col;

  cout << "Enter the number of rows in the matrix \n";
  cin >> row;
  cout << "Enter the number of columns in the matrix \n";
  cin >> col;

  int total = row * col;

  int** random = new int* [row];
  for (int i = 0; i < row; i++)
   random[i] = new int[row];

  fillnprint(row, col, random);
  SSN(row, col, random, total);
  genders(row, col, random, total);

  delete[]random;
  return 0;
}

//**************************************************************//
//                                                              //
//                 Function Name: fillnprint                    //
//        Parameters: int row, int col, int**a                  //
//     This functions stores random numbers from 1000 to 5999   //
//     in the array. It does this by using nested for loops and //
//     a random number generater function. Once the random      //
//     numbers are placed into the dynamic array, they are      //
//     prints to the screen. These random numbers represent     //
//     SSN's that will later be tested to tell weather they are //
//     even/odd, and which group they fit in                    //
//     (1000's, 2000's, 3000's, 4000's, 5000's)                 //
//                                                              //
//**************************************************************//

void fillnprint(int row, int col, int** a)
{
  int lb = 1000, ub = 5999;
  for (int i = 0; i < row; i++) {
   for (int j = 0; j < col; j++) {
    a[i][j] = (rand() % (ub - lb + 1)) + lb;
   }
  }

  cout << "=====================================================\n\n";
  cout << "The Matrix: \n";
  for (int i = 0; i < row; i++) {
   for (int j = 0; j < col; j++) {
    cout << a[i][j] << " ";
   }
   cout << endl;
  }
}

//**************************************************************//
//                                                              //
//                 Function Name: SSN                           //
//        Parameters: int row, int col, int**a, int total       //
//     This functions goes through the array and determines     //
//     weather the number is in the 1000's 2000's and so one.   //
//     all the way to 5000. It does this by creating a for loop //          
//     and if statements within it. Variables are incrememnted  //
//     If their for loop is satisifed by the number it is       //
//     testing. Afterwards, the information gathered is then    //
//     printed to the screen.                                   //
//                                                              //
//**************************************************************//

void SSN(int row, int col, int** a, int total)
{
  int num1 = 0;
  int num2 = 0;
  int num3 = 0;
  int num4 = 0;
  int num5 = 0;

  for (int i = 0; i < row; i++) {
   for (int j = 0; j < col; j++)
    {
     if (a[i][j] < 2000)
      num1++;
     else if (a[i][j] < 3000)
      num2++;
     else if (a[i][j] < 4000)
      num3++;
     else if (a[i][j] < 5000)
      num4++;
     else
      num5++;
    }
   }
  cout << "\n=====================================================\n\n";
  cout << "The following summarizes the SSN's in Tiny Ville";
  cout << "\nSSN: 1000s = " << num1;
  cout << "\nSSN: 2000s = " << num2;
  cout << "\nSSN: 3000s = " << num3;
  cout << "\nSSN: 4000s = " << num4;
  cout << "\nSSN: 5000s = " << num5;
  cout << "\nThe total # of habitants in Tiny Ville is " << total;
}

//**************************************************************//
//                                                              //
//                 Function Name: gender                        //
//        Parameters: int row, int col, int**a, int total       //
//     This functions goes through the array and determines     //
//     weather the number is even or odd. It does this          //
//     by taking the mod of each number in the array.           //
//     If the number is even, girl is incremented up by one.    //
//     If the number is off, guy is incrememnted up by one.     //
//     Afterwards, it prints out the information.               //
//                                                              //
//**************************************************************//

void genders(int row, int col, int** a, int total)
{
  int girl = 0;
  int guy = 0;

  for (int i = 0; i < row; i++) {
   for (int j = 0; j < col; j++)
   {
    if (a[i][j] % 2 == 0)
     girl++;
    else
     guy++;
   }
  }
  cout << "\n\n======================================================\n\n";
  cout << "The following summarizes the Genders in Tiny Ville\n";
  cout << "The total # of habitants in Tiny Ville is " << total;
  cout << "\nTiny Ville has " << girl << " women\n";
  cout << "Tiny Ville has " << guy << " men";
  cout << "\n======================================================\n";
}