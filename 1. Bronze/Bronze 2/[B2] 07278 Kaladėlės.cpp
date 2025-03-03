#include <iostream>
#include <array>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    array<int, 3> c;
    cin >> n >> c[0] >> c[1] >> c[2];

    pair<int, int> result = { -1,0 };
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= n + c[i]; j += c[i])
        {
            if (abs(n - j) < abs(n - result.second))
                result = { c[i],j };
        }
    }

    cout << result.first << ' ' << result.second << '\n';
}