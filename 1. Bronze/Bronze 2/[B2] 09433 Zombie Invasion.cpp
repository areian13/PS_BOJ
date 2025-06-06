#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        array<int, 20> map;
        for (int i = 0; i < 20; i++)
            cin >> map[i];

        for (int i = 20 - 1; i >= 1; i--)
        {
            map[i - 1] += map[i] / 2;
            map[i] %= 2;
        }
        for (int i = 0; i < 20; i++)
            cout << map[i] << ' ';
        cout << '\n';
    }
}