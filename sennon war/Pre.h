#ifndef PRE_H
#define PRE_H

#include <stdlib.h>
#include <iostream>
#include <map>
#include <unordered_set>
#include "Orb.h"

using namespace std;

class Data;

class Pre
{
    friend istream &get_pr(istream &is, Pre &pre);

public:
    Pre() = default;

    void psum(Data &dpr, Data &dpr_u, Orb &orb_pr, Orb &orb_pr_u);

    const unordered_set<string> orb_set =
        {
            "arc", "hea", "d_f", "r_c", "art", "val", "p_r", "mon", "ban", "w_w",
            "pir", "ass", "sol", "pri", "bis", "arm", "sam", "m_s", "v_h", "sai",
            "mag", "nin", "wit", "a_c", "ang", "m_a", "s_f", "dan", "d_r", "ran",
            "b_r", "man", "alc", "thi", "sha"
        };

private:
    char rare;
    int favor;
    bool if_ne;
    bool if_sk;
    string orb1;
    string orb2;
};

istream &get_pr(istream &is, Pre &pre)
{
    is >> pre.rare >> pre.favor >> pre.if_ne >> pre.if_sk >> pre.orb1;
    while(is >> pre.orb2)
        ;
    is.clear();
    return is;
}

void Pre::psum(Data &dpr, Data &dpr_u, Orb &orb_pr, Orb &orb_pr_u)
{
    if (orb_set.find(orb1) == orb_set.end() ||
       ((!orb2.empty()) && (orb_set.find(orb2) == orb_set.end())))
    {
        cerr << "DataError!?" << endl;
        exit(1);
    }
    int go_pr, or_pr;
    switch(rare)
    {
    case 'g':
    {
        go_pr = 20;
        or_pr = 1;
        break;
    }
    case 'w':
    {
        go_pr = 25;
        or_pr = 2;
        break;
    }
    case 'b':
    {
        go_pr = 30;
        or_pr = 3;
        break;
    }
    default:
        break;
    }
    if(if_sk)
    {
        go_pr = go_pr * 2;
        or_pr = or_pr * 2;
    }
    if(if_ne)
    {
        dpr.gold += go_pr;
        ++dpr.e_cry;
        dpr.f_ite += (100 - favor);
        *orb_pr.map_or[orb1] += or_pr;
        if(!orb2.empty())
            *orb_pr.map_or[orb2] += or_pr;
    }
    dpr_u.gold += go_pr;
    ++dpr_u.e_cry;
    dpr_u.f_ite += (100 - favor);
    *orb_pr_u.map_or[orb1] += or_pr;
    if(!orb2.empty())
        *orb_pr_u.map_or[orb2] += or_pr;
}

#endif // PRE
