#ifndef ORB_H_1_1
#define ORB_H_1_1

#include <iostream>
#include <string>

using namespace std;

class Pre;

class Orb
{
    friend class Pre;
    friend istream &input(istream &is, Orb &dor);
    friend ostream &output(ostream &os, Orb &dor);

public:
    Orb() = default;
    Orb &combine(string &str, Orb &dor);

private:
    int ost[9][4];
};

istream &input(istream &is, Orb &dor)
{
    for (int (&i)[4] : dor.ost)
        for (int &j : i)
            is >> j;
    return is;
}

ostream &output(ostream &os, Orb &dor)
{
    os << "orb_week" << '\n'
       << "arc:" << dor.ost[4][3] << " " << "hea:" << dor.ost[5][1] << " " << "d_f:" << dor.ost[2][0] << " " << "r_c:" << dor.ost[6][3] << " " << "art:" << dor.ost[7][1] << '\n'
       << "val:" << dor.ost[0][2] << " " << "p_r:" << dor.ost[1][3] << " " << "mon;" << dor.ost[2][1] << " " << "ban:" << dor.ost[1][0] << " " << "w_w:" << dor.ost[7][0] << '\n'
       << "pir:" << dor.ost[5][3] << " " << "ass:" << dor.ost[0][3] << " " << "sol:" << dor.ost[0][0] << " " << "pri:" << dor.ost[6][1] << " " << "bis:" << dor.ost[6][2] << '\n'
       << "arm:" << dor.ost[0][1] << " " << "sam:" << dor.ost[1][1] << " " << "m_s:" << dor.ost[2][3] << " " << "v_h:" << dor.ost[6][0] << " " << "sai:" << dor.ost[3][2] << '\n'
       << "mag:" << dor.ost[5][0] << " " << "nin:" << dor.ost[1][2] << " " << "wit:" << dor.ost[5][2] << " " << "a_c:" << dor.ost[2][2] << " " << "ang:" << dor.ost[3][0] << '\n'
       << "m_a:" << dor.ost[4][3] << " " << "s_f:" << dor.ost[3][3] << " " << "dan:" << dor.ost[7][2] << " " << "d_r:" << dor.ost[4][1] << " " << "ran:" << dor.ost[8][0] << '\n'
       << "b_r:" << dor.ost[4][2] << " " << "man:" << dor.ost[3][1] << " " << "alc:" << dor.ost[7][3] << " " << "thi:" << dor.ost[8][1] << " " << "sha:" << dor.ost[8][2] << endl;
       return os;
}

Orb& Orb::combine(string &str, Orb &dor)
{
    switch(str)
    {
    case "sol":
        {
        ++dor.ost[0][0];
        break;
        }
    default:
        {

        }
    }
}
#endif
