#ifndef DATA_H
#define DATA_H

#include <iostream>

using namespace std;

class Pre;

class Data
{
    friend class Pre;
    friend istream &read(istream &is, Data &account);
    friend ostream &print(ostream &os, Data &account);
public:

private:
    int gold = 0;
    int f_ite = 0;
    double e_cry = 0.0;
    int s_cry = 0;
    int chrisma = 0;
    int stamina = 0;
};

istream &read(istream &is, Data &account)
{
    is >> account.gold >> account.f_ite >> account.e_cry >> account.s_cry;
    return is;
}

ostream &print(ostream &os, Data &account)
{
    os << "money: " << account.gold << " favor: " << account.f_ite
       <<" e_crys: " << account.e_cry << " s_crys " << account.s_cry << '\n' << endl;
    return os;
}

#endif
