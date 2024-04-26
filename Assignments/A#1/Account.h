#ifndef ACCOUNT_H
#define ACCOUNT_H
using std::string;
using std::vector;

class date
{
private:
    int year;
    int month;
    int day;
public:
    date();
    void setdate(int d, int m, int y);
    void getdate();
};

class account
{
private:

    vector <long> accountnumber;
    vector<char> accounttype;
    vector<string> name;
    vector<double> balance;
    date date_of_last_payment;
    int count = 0;
public:
    account(string answer);
    ~account();
    void setdata();
    void printdata();
    void increase();
    void decrease();
    void transferwithin();
    void transferoutside();
};
#endif 
