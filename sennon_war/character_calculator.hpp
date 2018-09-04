#ifndef MY_CALCULATOR_HPP
#define MY_CALCULATOR_HPP

#include <iostream>
#include <string>
#include <math.h>
#include <utility>

using std::array;
using std::istream;
using status = std::pair<int, int>;
using std::round;

class Calculator {
    friend istream &read(istream &is, Calculator &cal);

public:
    Calculator() = default;
    Calculator(int r, status s): rarity(r), cur(s), max_level(levels[r]), pre(max_level, 0) { show_all(); }
    Calculator(int r, status sc, status sp): rarity(r), cur(sc), max_level(levels[r]), pre(sp) { show_all(); }
    Calculator(istream &is) { read(is, *this); }

    static void set_bonus(double);
    int to_exp(status s);
    status to_status(int);
    int how_many_need();
    void show_all();
    void pre(int);
    void cur(int, int, int);
    void cur(int, int, int, int);
    void add_pa();
    void add_sb();
    void add_ba();
    void add_nb();
    istream &catch(istream &is);

private:
    static const array<int, 6> levels = { 30, 40, 55, 99, 99, 99 };
    static const array<double, 6> rare_bonus = { 1.0, 1.1, 1.2, 1.3, 1.4, 1.5 };
    static const array<int, 6> small_blesses = {0, 0, 4000, 18000, 19000, 20000 };
    static const int pla_armor = 8000;
    static const int bla_armor = 80000;
    static const int normal_bless = 160000;
    static const array<int, 99> exp_list = {
        0, 32, 33, 35, 35, 37, 39, 39, 41, 42, 85,
        88, 92, 95, 98, 102, 105, 108, 112, 115, 170,
        176, 183, 190, 197, 203, 210, 217, 224, 230, 283,
        294, 305, 316, 328, 339, 350, 362, 372, 385, 565,
        587, 610, 633, 656, 677, 701, 723, 746, 768, 848,
        881, 915, 950, 983, 1017, 1050, 1085, 1119, 1152, 1130,
        1175, 1221, 1265, 1311, 1356, 1401, 1446, 1492, 1537, 1412,
        1469, 1525, 1582, 1639, 1695, 1751, 1808, 1864, 1921, 1978,
        2056, 2136, 2215, 2293, 2373, 2452, 2531, 2610, 2690, 1977,
        2057, 2135, 2215, 2294, 2373, 2451, 2532, 2610,
    };
    static const array<int, 99> exp_sum = {
        0, 32, 65, 100, 135, 172, 211, 250, 291, 333, 418,
        506, 598, 693, 791, 893, 998, 1106, 1218, 1333, 1503,
        1679, 1862, 2052, 2249, 2452, 2662, 2879, 3103, 3333, 3616,
        3910, 4215, 4531, 4859, 5198, 5548, 5910, 6282, 6667, 7232,
        7819, 8429, 9062, 9718, 10395, 11096, 11819, 12565, 13333, 14181,
        15062, 15977, 16927, 17910, 18927, 19977, 21062, 22181, 23333, 24463,
        25638, 26859, 28124, 29435, 30791, 32192, 33638, 35130, 36667, 38079,
        39548, 41073, 42655, 44294, 45989, 47740, 49548, 51412, 53333, 55311,
        57367, 59503, 61718, 64011, 66384, 68836, 71367, 73977, 76667, 78644,
        80701, 82836, 85051, 87345, 89718, 92169, 94701, 97311,
    };
    int rarity = 0;
    static double bonus = 0;
    status cur(1, 0);
    int max_level = 0;
    status pre(99, 0);
};

void Calculator::set_bonus(double newbonus)
{
    bonus = newbonus;
}

istream &read(istream &i, Calculator &cal)
{
    int tem;
    i >> cal.rarity >> cal.cur.first >> tem >> cal.pre.first;
    cal.cur.second = round(cal.exp_list[cal.cur.first] * cal.rare_bonus[cal.rarity]) - tem;
    cal.pre.second = 0;
}

int Calculator::to_exp(status s)
{
    return round(levels[s.first - 1] * rare_bonus[rarity - 1]) + s.second;
}

status Calculator::to_status(int i)
{
    auto ptr = std::find_if(exp_sum.begin(), exp_sum.end(),
                            [i](const int s) { return s >= round(i / rare_bonus[rarity - 1])}; );
    return std::make_pair(1 + ptr - exp_sum.begin(), i - round(*ptr * rare_bonus[rarity - 1]);
}

int Calculator::how_many_need()
{
    return to_exp(pre) - to_exp(cur);
}

void Calculator::show_all()
{
    std::cout << "current status: " << cur.first << " " << cur.second << '\n'
              << "prediction status: " << pre.first >> " " << pre.second << '\n'
              << "need exp:" << how_many_need() << '\n' << std::endl;
}

void Calculator::pre(int i)
{
    pre = std::make_pair(i, 0);
    show_all();
}

void Calculator::cur(int rare, int level, int exp)
{
    rarity = rare;
    cur.first = level;
    cur.second = round(exp_list[level - 1] * rare_bonus[rare - 1]) - exp;
    show_all();
}

void Calculator::cur(int rare, int level, int exp, int prelevel)
{
    rarity = rare;
    cur.first = level;
    cur.second = round(exp_list[level - 1] * rare_bonus[rare - 1]) - exp;
    pre(prelevel);
    show_all();
}

void Calculator::add_pa()
{
    pre = to_status(to_exp(pre) - pla_armor * bonus);
    show_all();
}

void Calculator::add_sb()
{
    pre = to_status(to_exp(pre) - small_blesses[rarity - 1] * bonus);
    show_all();
}

void Calculator::add_ba()
{
    pre = to_status(to_exp(pre) - bla_armor * bonus);
    show_all();
}

void Calculator::add_ba()
{
    pre = to_status(to_exp(pre) - normal_bless * bonus);
    show_all();
}
#endif // CHARACTER_HPP
