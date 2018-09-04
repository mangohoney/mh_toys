#include "Vector.hpp"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    Vector<int> s0;
    Vector<int> s1(5);
    Vector<int> s2(s1);
    Vector<int> s3 = s1;
    s0 = s1;
    s0.resize(6);
    s1.resize(30);
    s2.reserve(5);
    s3.reserve(6);
    cout << s0[0] << " " << s0.size() << " " <<  *s0.end() << " " << s0.capacity() << " " << s0.back() << '\n';
    cout << s1[0] << " " << s1.size() << " " <<  *s1.end() << " " << s1.capacity() << " " << s1.back() << '\n';
    cout << s2[0] << " " << s2.size() << " " <<  *s2.end() << " " << s2.capacity() << " " << s2.back() << '\n';
    cout << s3[0] << " " << s3.size() << " " <<  *s3.end() << " " << s3.capacity() << " " << s3.back() << '\n';
    s3.push_back(0);
    cout << s3[0] << " " << s3.size() << " " <<  *s3.end() << " " << s3.capacity() << " " << s3.back() << '\n';
    s2.pop_back();
    cout << s2[0] << " " << s2.size() << " " <<  *s2.end() << " " << s2.capacity() << " " << s2.back() << '\n';
    cout << endl;
    return 0;
}
