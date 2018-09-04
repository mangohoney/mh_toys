#ifndef ORB_H_1_2
#define ORB_H_1_2

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
    Orb()
    {
        for (int i = 0; i != 7; ++i)
            for (int j = 0; j != 5; ++j)
            ost[i][j] = 0;
        map_or =
        {
            {"arc:", ost[0][0]},
            {"hea:", ost[0][1]},
            {"d_f:", ost[0][2]},
            {"r_c:", ost[0][3]},
            {"art:", ost[0][4]},
            {"val:", ost[1][0]},
            {"p_r:", ost[1][1]},
            {"mon;", ost[1][2]},
            {"ban:", ost[1][3]},
            {"w_w:", ost[1][4]},
            {"pir:", ost[2][0]},
            {"ass:", ost[2][1]},
            {"sol:", ost[2][2]},
            {"pri:", ost[2][3]},
            {"bis:", ost[2][4]},
            {"arm:", ost[3][0]},
            {"sam:", ost[3][1]},
            {"m_s:", ost[3][2]},
            {"v_h:", ost[3][3]},
            {"sai:", ost[3][4]},
            {"mag:", ost[4][0]},
            {"nin:", ost[4][1]},
            {"wit:", ost[4][2]},
            {"a_c:", ost[4][3]},
            {"ang:", ost[4][4]},
            {"m_a:", ost[5][0]},
            {"s_f:", ost[5][1]},
            {"dan:", ost[5][2]},
            {"d_r:", ost[5][3]},
            {"ran:", ost[5][4]},
            {"b_r:", ost[6][0]},
            {"man:", ost[6][1]},
            {"alc:", ost[6][2]},
            {"thi:", ost[6][3]},
            {"sha:", ost[6][4]}
        };
    };


private:
    int ost[7][5];
    map<string, int*> map_or;
};

istream &input(istream &is, Orb &dor)
{
    is  >> dor.ost[2][2] >> dor.ost[3][0] >> dor.ost[1][0] >> dor.ost[2][1]
        >> dor.ost[1][3] >> dor.ost[3][1] >> dor.ost[4][1] >> dor.ost[1][1]
        >> dor.ost[0][2] >> dor.ost[1][2] >> dor.ost[4][3] >> dor.ost[3][2]
        >> dor.ost[4][4] >> dor.ost[6][1] >> dor.ost[3][4] >> dor.ost[5][1]
        >> dor.ost[5][0] >> dor.ost[5][3] >> dor.ost[6][0] >> dor.ost[0][0]
        >> dor.ost[4][0] >> dor.ost[0][1} >> dor.ost[4][2] >> dor.ost[2][0]
        >> dor.ost[3][3] >> dor.ost[2][3] >> dor.ost[2][4] >> dor.ost[0][3]
        >> dor.ost[1][4] >> dor.ost[0][4] >> dor.ost[5][2] >> dor.ost[6][2]
        >> dor.ost[5][4] >> dor.ost[6][3] >> dor.ost[6][4];
    return is;
}

ostream &output(ostream &os, Orb &dor)
{
    os << "arc:" << dor.ost[0][0] << " " << "hea:" << dor.ost[0][1] << " " << "d_f:" << dor.ost[0][2] << " " << "r_c:" << dor.ost[0][3] << " " << "art:" << dor.ost[0][4] << '\n'
       << "val:" << dor.ost[1][0] << " " << "p_r:" << dor.ost[1][1] << " " << "mon;" << dor.ost[1][2] << " " << "ban:" << dor.ost[1][3] << " " << "w_w:" << dor.ost[1][4] << '\n'
       << "pir:" << dor.ost[2][0] << " " << "ass:" << dor.ost[2][1] << " " << "sol:" << dor.ost[2][2] << " " << "pri:" << dor.ost[2][3] << " " << "bis:" << dor.ost[2][4] << '\n'
       << "arm:" << dor.ost[3][0] << " " << "sam:" << dor.ost[3][1] << " " << "m_s:" << dor.ost[3][2] << " " << "v_h:" << dor.ost[3][3] << " " << "sai:" << dor.ost[3][4] << '\n'
       << "mag:" << dor.ost[4][0] << " " << "nin:" << dor.ost[4][1] << " " << "wit:" << dor.ost[4][2] << " " << "a_c:" << dor.ost[4][3] << " " << "ang:" << dor.ost[4][4] << '\n'
       << "m_a:" << dor.ost[5][0] << " " << "s_f:" << dor.ost[5][1] << " " << "dan:" << dor.ost[5][2] << " " << "d_r:" << dor.ost[5][3] << " " << "ran:" << dor.ost[5][4] << '\n'
       << "b_r:" << dor.ost[6][0] << " " << "man:" << dor.ost[6][1] << " " << "alc:" << dor.ost[6][2] << " " << "thi:" << dor.ost[6][3] << " " << "sha:" << dor.ost[6][4] << endl;
    return os;
}


#endif
