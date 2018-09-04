#include "Data.h"
#include "Pre.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int i;
    ifstream ifd, ifo, ifp;
    if(cin >> i)
    {
        switch(i)
        {
        case 1:
        {
            ifd.open("acc1_dat.txt");
            ifo.open("acc1_orb.txt");
            ifp.open("acc1_pre.txt");
            break;
        }
        case 2:
        {
            ifd.open("acc2_dat.txt");
            ifo.open("acc2_orb.txt");
            ifp.open("acc2_pre.txt");
            break;
        }
        case 3:
        {
            ifd.open("acc3_dat.txt");
            ifo.open("acc3_orb.txt");
            ifp.open("acc3_pre.txt");
            break;
        }
        default:
        {
            cerr << "Error!" << endl;
            break;
        }
        }

        Data data;
        read(ifd, data);
        Orb orb;
        input(ifo, orb);
        string spr;
        Data dpr;
        Data dpr_u;
        Orb orb_pr;
        Orb orb_pr_u;
        while (getline(ifp, spr))
        {
            istringstream istpr(spr);
            cout << spr << '\n' << endl;
            Pre pre;
            if(get_pr(istpr,pre))
            {
            pre.psum(dpr, dpr_u, orb_pr, orb_pr_u);
            }
        }
        print(cout, data);
        print(cout, dpr);
        print(cout, dpr_u);
        output(cout, contrast(orb, orb_pr));
        output(cout, contrast(orb, orb_pr_u));
        cout << endl;
        return 0;
    }
}
