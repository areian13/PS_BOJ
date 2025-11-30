#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string print(double d)
{
    return (int)d == d ? to_string((int)d) : to_string((int)d) + ".5";
}

int main()
{
    FastIO;

    vector<double> p1(3), p2(6);
    for (int i = 0; i < 3; i++)
        cin >> p1[i];
    for (int i = 0; i < 6; i++)
        cin >> p2[i];

    p1[0] -= p2[4] + p2[3] / 2 + p2[5] / 2; p1[0] = max(-p1[0], 0.);
    p1[1] -= p2[0] + p2[1] / 2 + p2[5] / 2; p1[1] = max(-p1[1], 0.);
    p1[2] -= p2[2] + p2[1] / 2 + p2[3] / 2; p1[2] = max(-p1[2], 0.);
    cout << print(p1[0]) << ' ' << print(p1[1]) << ' ' << print(p1[2]) << '\n';
}