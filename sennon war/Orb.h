#ifndef ORB_H_1_5
#define ORB_H_1_5

#include <iostream>
#include <map>
#include <array>

using std::istream;
using std::ostream;
using std::map;
using std::array;
using std::string;

class Pre;

class Orb
{
    friend class Pre;
    friend istream &input(istream &is, Orb &dor);
    friend ostream &output(ostream &os, const Orb &dor);
    friend Orb contrast(const Orb &orb1, const Orb &orb2);

public:
    Orb() : ost({35, 0})
    {
        for (int i = 0; i != 35; ++i)
            ost[i] = 0;
        map_or =
        {
            {"arc", &ost[0]},
            {"hea", &ost[1]},
            {"d_f", &ost[2]},
            {"r_c", &ost[3]},
            {"art", &ost[4]},
            {"val", &ost[5]},
            {"p_r", &ost[6]},
            {"mon", &ost[7]},
            {"ban", &ost[8]},
            {"w_w", &ost[9]},
            {"pir", &ost[10]},
            {"ass", &ost[11]},
            {"sol", &ost[12]},
            {"pri", &ost[13]},
            {"bis", &ost[14]},
            {"arm", &ost[15]},
            {"sam", &ost[16]},
            {"m_s", &ost[17]},
            {"v_h", &ost[18]},
            {"sai", &ost[19]},
            {"mag", &ost[20]},
            {"nin", &ost[21]},
            {"wit", &ost[22]},
            {"a_c", &ost[23]},
            {"ang", &ost[24]},
            {"m_a", &ost[25]},
            {"s_f", &ost[26]},
            {"dan", &ost[27]},
            {"d_r", &ost[28]},
            {"ran", &ost[29]},
            {"b_r", &ost[30]},
            {"man", &ost[31]},
            {"alc", &ost[32]},
            {"thi", &ost[33]},
            {"sha", &ost[34]}
        };
    };

private:
    array<int, 35> ost;
    map<string, int*> map_or;
};

istream &input(istream &is, Orb &dor)
{
    for (int i = 0; i != 35; ++i)
        is >> dor.ost[i];
    return is;
}

ostream &output(ostream &os, const Orb &dor)
{
    os << "arc:" << dor.ost[0] << " " << "hea:" << dor.ost[1] << " " << "d_f:" << dor.ost[2] << " " << "r_c:" << dor.ost[3] << " " << "art:" << dor.ost[4] << '\n'
       << "val:" << dor.ost[5] << " " << "p_r:" << dor.ost[6] << " " << "mon;" << dor.ost[7] << " " << "ban:" << dor.ost[8] << " " << "w_w:" << dor.ost[9] << '\n'
       << "pir:" << dor.ost[10] << " " << "ass:" << dor.ost[11] << " " << "sol:" << dor.ost[12] << " " << "pri:" << dor.ost[13] << " " << "bis:" << dor.ost[14] << '\n'
       << "arm:" << dor.ost[15] << " " << "sam:" << dor.ost[16] << " " << "m_s:" << dor.ost[17] << " " << "v_h:" << dor.ost[18] << " " << "sai:" << dor.ost[19] << '\n'
       << "mag:" << dor.ost[20] << " " << "nin:" << dor.ost[21] << " " << "wit:" << dor.ost[22] << " " << "a_c:" << dor.ost[23] << " " << "ang:" << dor.ost[24] << '\n'
       << "m_a:" << dor.ost[25] << " " << "s_f:" << dor.ost[26] << " " << "dan:" << dor.ost[27] << " " << "d_r:" << dor.ost[28] << " " << "ran:" << dor.ost[29] << '\n'
       << "b_r:" << dor.ost[30] << " " << "man:" << dor.ost[31] << " " << "alc:" << dor.ost[32] << " " << "thi:" << dor.ost[33] << " " << "sha:" << dor.ost[34] << '\n' << '\n' << endl;
    return os;
}

Orb contrast(const Orb &orb1, const Orb &orb2)
{
    Orb tem;
    for (int i = 0; i != 35; ++i)
        tem.ost[i] = orb1.ost[i] - orb2.ost[i];
    return tem;
}
#endif
