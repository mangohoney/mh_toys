#include "my_calculator.hpp"

#include <iostream>
#include <algorithm>

using namespace std;

const std::array<int, 6> Calculator::levels = { 30, 40, 55, 99, 99, 99 };
const std::array<double, 6> Calculator::rare_bonus = { 1.0, 1.1, 1.2, 1.3, 1.4, 1.5 };
const std::array<int, 6> Calculator::small_blesses = {0, 0, 4000, 18000, 19000, 20000 };
const std::array<int, 99> Calculator::exp_list = {
        0, 32, 33, 35, 35, 37, 39, 39, 41, 42, 85,
        88, 92, 95, 98, 102, 105, 108, 112, 115, 170,
        176, 183, 190, 197, 203, 210, 217, 224, 230, 283,
        294, 305, 316, 328, 339, 350, 362, 372, 385, 565,
        587, 610, 633, 656, 677, 701, 723, 746, 768, 848,
        881, 915, 950, 983, 1017, 1050, 1085, 1119, 1152, 1130,
        1175, 1221, 1265, 1311, 1356, 1401, 1446, 1492, 1537, 1412,
        1469, 1525, 1582, 1639, 1695, 1751, 1808, 1864, 1921, 1978,
        2056, 2136, 2215, 2293, 2373, 2452, 2531, 2610, 2690, 1977,
        2057, 2135, 2215, 2294, 2373, 2451, 2532, 2610
    };
const std::array<int, 99> Calculator::exp_sum = {
        0, 32, 65, 100, 135, 172, 211, 250, 291, 333, 418,
        506, 598, 693, 791, 893, 998, 1106, 1218, 1333, 1503,
        1679, 1862, 2052, 2249, 2452, 2662, 2879, 3103, 3333, 3616,
        3910, 4215, 4531, 4859, 5198, 5548, 5910, 6282, 6667, 7232,
        7819, 8429, 9062, 9718, 10395, 11096, 11819, 12565, 13333, 14181,
        15062, 15977, 16927, 17910, 18927, 19977, 21062, 22181, 23333, 24463,
        25638, 26859, 28124, 29435, 30791, 32192, 33638, 35130, 36667, 38079,
        39548, 41073, 42655, 44294, 45989, 47740, 49548, 51412, 53333, 55311,
        57367, 59503, 61718, 64011, 66384, 68836, 71367, 73977, 76667, 78644,
        80701, 82836, 85051, 87345, 89718, 92169, 94701, 97311
    };
bool Calculator::if_mo = true;

void catch_(istream &is, Calculator &cal)
{
    int tem;
    int rar, lev, exp, aim;
    while (is >> tem)
    {
        switch(tem)
        {
        case 0:
        {
            is >> rar >> lev >> exp >> aim;
            cal.new_c(rar, lev, exp, aim);
            break;
        }
        case 1:
        {
            cal.add_pa();
            break;
        }
        case 2:
        {
            cal.add_sb();
            break;
        }
        case 3:
        {
            cal.add_ba();
            break;
        }
        case 4:
        {
            cal.add_nb();
            break;
        }
        case 5:
        {
            is >> aim;
            cal.aim_change(aim);
            break;
        }
        case 9:
        {
            Calculator::change_if_mo();
            break;
        }
        default:
        { }
        }
    }
}

istream &read(istream &is, Calculator &cal)
{
    is >> cal.rarity >> cal.cur.first >> cal.cur.second >> cal.aim_level;
    cal.pre = make_pair(cal.aim_level, 0);
    return is;
}

void Calculator::change_if_mo()
{
    if_mo = !if_mo;
}

double Calculator::get_bonus()
{
    return if_mo ? 1.1 : 1.0;
}

int Calculator::to_exp(status s)
{
    if (s.first < 99)
    {
        return round(exp_sum[s.first] * rare_bonus[rarity - 1]) - s.second;
    }
    else
    {
        return round(exp_sum[98] * rare_bonus[rarity - 1]);
    }
}

Calculator::status Calculator::to_status(int i)
{
    auto ptr = find_if(exp_sum.begin(), exp_sum.end(),
               [this, i](const int &s) { return s >= round(i / rare_bonus[rarity - 1]); });
    return make_pair(ptr - exp_sum.begin(), round(*ptr * rare_bonus[rarity - 1]) - i);
}

int Calculator::how_many_need()
{
    return to_exp(pre) - to_exp(cur);
}

void Calculator::show_all()
{
    cout << "current status: " << cur.first << " " << cur.second << '\n'
         << "prediction status: " << pre.first << " " << pre.second << '\n'
         << "need exp:" << how_many_need() << '\n' << endl;
}

void Calculator::aim_change(int i)
{
    aim_level = i;
    pre = make_pair(i, 0);
    show_all();
}

void Calculator::new_c(int rare, int level, int exp, int aimlevel)
{
    rarity = rare;
    cur = make_pair(level, exp);
    aim_level = aimlevel;
    pre = make_pair(aimlevel, 0);
    show_all();
}

void Calculator::add_pa()
{
    pre = to_status(to_exp(pre) - round(pla_armor * get_bonus()));
    show_all();
}

void Calculator::add_sb()
{
    pre = to_status(to_exp(pre) - round(small_blesses[rarity - 1] * get_bonus()));
    show_all();
}

void Calculator::add_ba()
{
    pre = to_status(to_exp(pre) - round(bla_armor * get_bonus()));
    show_all();
}

void Calculator::add_nb()
{
    pre = to_status(to_exp(pre) - round(normal_bless * get_bonus()));
    show_all();
}
