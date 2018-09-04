#include <map>
#include <iostream>
#include <vector>

using namespace std;

struct tac
{
    tac(int n){
        for (int i = 0, i != 2, ++i)
        for (int j = 0, j != 3, ++j)
            tre[i][j] = n;
    };
    int tre[2][3];
};
int main()
{
    tac ta();
    array<int*, 6> tra;
    int k = 0;
    for(int i = 0; i != 2; ++i)
    {
        for(int j = 0; j != 3; ++j)
        {
            tra[k] = &ta.tre[i][j];
            ++k;
        }
    }
    map<string, int *> ma_pr = {
    { "arc", tra[0]},
    { "sol", tra[1]},
    { "b_r", tra[2]},
    { "aaa", tra[3]},
    { "bbb", tra[4]},
    { "ccc", tra[5]}
    };
    string str;
    if(cin >> str)
        ++*ma_pr[str];
    for (auto &w : ma_pr)
        cout << w.first << " occurs " << *w.second << endl;
    return 0;
}
