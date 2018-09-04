#include <map>
#include <iostream>
#include <vector>

using namespace std;

struct tac
{
    tac()
    {
        for (int i = 0; i != 2; ++i)
            for (int j = 0; j != 3; ++j)
                tre[i][j] = 0;
        ma_pr =
        {
            { "arc", &tre[0][0]},
            { "sol", &tre[0][1]},
            { "b_r", &tre[0][2]},
            { "aaa", &tre[1][0]},
            { "bbb", &tre[1][1]},
            { "ccc", &tre[1][2]}
        };
    };
    int tre[2][3];
    map<string, int*> ma_pr;

};
int main()
{
    tac ta;
    string str;
    if(cin >> str)
        ++*ta.ma_pr[str];
    for (auto &w : ta.ma_pr)
        cout << w.first << " occurs " << *w.second << endl;
    for (int i = 0; i != 2; ++i)
        for (int j = 0; j != 3; ++j)
            cout << ta.tre[i][j] << endl;
    return 0;
}
