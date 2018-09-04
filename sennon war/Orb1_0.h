#ifndef ORB_H_1_0
#define ORB_H_1_0

#include <iostream>

using namespace std;

class Pre;

class Orb
{
    friend class Pre;
    friend istream &input(istream &is, Orb &dor);
    friend ostream &output(ostream &os, Orb &dor);
    friend ostream &w_output(ostream &os, Orb &dor);
public:
    Orb &combine(string &str, Orb &dor);

private:
    int sol = 0; int arm = 0; int val = 0; int ass = 0;
    int ban = 0; int sam = 0; int nin = 0; int p_r = 0;
    int d_f = 0; int mon = 0; int a_c = 0; int m_s = 0;
    int ang = 0; int man = 0; int sai = 0; int s_f = 0;
    int m_a = 0; int d_r = 0; int b_r = 0; int arc = 0;
    int mag = 0; int hea = 0; int wit = 0; int pir = 0;
    int v_h = 0; int pri = 0; int bis = 0; int r_c = 0;
    int w_w = 0; int art = 0; int dan = 0; int alc = 0;
    int ran = 0; int thi = 0; int sha = 0;
};

istream &input(istream &is, Orb &dor)
{
    is >> dor.sol >> dor.arm >> dor.val >> dor.ass
       >> dor.ban >> dor.sam >> dor.nin >> dor.p_r
       >> dor.d_f >> dor.mon >> dor.a_c >> dor.m_s
       >> dor.ang >> dor.man >> dor.sai >> dor.s_f
       >> dor.m_a >> dor.d_r >> dor.b_r >> dor.arc
       >> dor.mag >> dor.hea >> dor.wit >> dor.pir
       >> dor.v_h >> dor.pri >> dor.bis >> dor.r_c
       >> dor.w_w >> dor.art >> dor.dan >> dor.alc
       >> dor.ran >> dor.thi >> dor.sha;
    return is;
}

ostream &output(ostream &os, Orb &dor)
{
    os << dor.sol << " " << dor.arm << " " << dor.val << " " << dor.ass << "\n"
       << dor.ban << " " << dor.sam << " " << dor.nin << " " << dor.p_r << "\n"
       << dor.d_f << " " << dor.mon << " " << dor.a_c << " " << dor.m_s << "\n"
       << dor.ang << " " << dor.man << " " << dor.sai << " " << dor.s_f << "\n"
       << dor.m_a << " " << dor.d_r << " " << dor.b_r << " " << dor.arc << "\n"
       << dor.mag << " " << dor.hea << " " << dor.wit << " " << dor.pir << "\n"
       << dor.v_h << " " << dor.pri << " " << dor.bis << " " << dor.r_c << "\n"
       << dor.w_w << " " << dor.art << " " << dor.dan << " " << dor.alc << "\n"
       << dor.ran << " " << dor.thi << " " << dor.sha << endl;
       return os;
}

ostream &w_output(ostream &os, Orb &dor)
{
    os << "orb_week" << '\n'
       << "arc:" << dor.arc << " " << "hea:" << dor.hea << " " << "d_f:" << dor.d_f << " " << "r_c:" << dor.r_c << " " << "art:" << dor.art << '\n'
       << "val:" << dor.val << " " << "p_r:" << dor.p_r << " " << "mon;" << dor.mon << " " << "ban:" << dor.ban << " " << "w_w:" << dor.w_w << '\n'
       << "pir:" << dor.pir << " " << "ass:" << dor.ass << " " << "sol:" << dor.sol << " " << "pri:" << dor.pri << " " << "bis:" << dor.bis << '\n'
       << "arm:" << dor.arm << " " << "sam:" << dor.sam << " " << "m_s:" << dor.m_s << " " << "v_h:" << dor.v_h << " " << "sai:" << dor.sai << '\n'
       << "mag:" << dor.mag << " " << "nin:" << dor.nin << " " << "wit:" << dor.wit << " " << "a_c:" << dor.a_c << " " << "ang:" << dor.ang << '\n'
       << "m_a:" << dor.m_a << " " << "s_f:" << dor.s_f << " " << "dan:" << dor.dan << " " << "d_r:" << dor.d_r << " " << "ran:" << dor.ran << '\n'
       << "arc:" << dor.arc << " " << "man:" << dor.man << " " << "alc:" << dor.alc << " " << "thi:" << dor.thi << " " << "sha:" << dor.sha << endl;
       return os;
}

Orb& Orb::combine(string &str, Orb &dor)
{
    switch(str)
    {
    case "arc":
        ++dor.arc;
        break;
    default:

    }
}
#endif
