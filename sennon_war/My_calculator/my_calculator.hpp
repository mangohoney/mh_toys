#ifndef MY_CALCULATOR_HPP
#define MY_CALCULATOR_HPP

#include <istream>
#include <array>
#include <utility>

class Calculator {
    friend std::istream &read(std::istream &is, Calculator &cal);
    friend void catch_(std::istream &is, Calculator &cal);

public:
    typedef std::pair<int, int> status;

    Calculator() = default;
    Calculator(int r, int i, int j, int m): rarity(r), cur(std::make_pair(i, j)),
                                            max_level(levels[r]), aim_level(m), pre(std::make_pair(m, 0)) { show_all(); }
    Calculator(std::istream &is) { read(is, *this); }

    static void change_if_mo();
    static double get_bonus();
    int to_exp(status s);
    status to_status(int);
    int how_many_need();
    void show_all();
    void aim_change(int);
    void new_c(int, int, int, int);
    void add_pa();
    void add_sb();
    void add_ba();
    void add_nb();

    static bool if_mo;

private:
    static const std::array<int, 6> levels;
    static const std::array<double, 6> rare_bonus;
    static const std::array<int, 6> small_blesses;
    static const std::array<int, 99> exp_list;
    static const std::array<int, 99> exp_sum;
    static const int pla_armor = 8000;
    static const int bla_armor = 40000;
    static const int normal_bless = 160000;
    int rarity = 0;
    status cur = std::make_pair(1, 32);
    int max_level = 99;
    int aim_level = 99;
    status pre = std::make_pair(99, 0);
};

#endif // CHARACTER_HPP
