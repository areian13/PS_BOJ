#include <iostream>
#include <array>
#include <algorithm>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<array<int, 2>, 3> armys;
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < 3; i++)
            cin >> armys[i][j];
    }

    int maxArmy = 0;
    for (int i = 0; i < 3; i++)
        maxArmy = max(maxArmy, armys[i][0] * armys[i][1]);

    array<string, 3> names = { "Joffrey","Robb","Stannis" };
    for (int i = 0; i < 3; i++)
    {
        if (armys[i][0] * armys[i][1] == maxArmy)
            cout << names[i] << ' ';
    }
    cout << '\n';
}