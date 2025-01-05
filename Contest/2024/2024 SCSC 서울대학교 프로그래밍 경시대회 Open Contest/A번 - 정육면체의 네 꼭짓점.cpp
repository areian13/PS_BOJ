#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsSameSide(array<int, 4>& k)
{
    static array<array<int, 3>, 8> p =
    {
        array<int, 3>
        {0,0,0},{0,0,1},{0,1,0},{0,1,1},
        {1,0,0},{1,0,1},{1,1,0},{1,1,1}
    };

    for (int i = 0; i < 3; i++)
    {
        bool isSame = true;
        for (int j = 0; j < 3; j++)
            isSame &= (p[k[j]][i] == p[k[j + 1]][i]);

        if (isSame)
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        array<int, 4> k;
        for (int i = 0; i < 4; i++)
            cin >> k[i];

        string result = (IsSameSide(k) ? "YES" : "NO");
        cout << result << '\n';
    }
}