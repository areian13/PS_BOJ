#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int a, b;
        cin >> a >> b;

        bool isSwap = false;
        if (a < b)
        {
            swap(a, b);
            isSwap = true;
        }

        if (a % 2 != b % 2)
            cout << -1 << '\n';
        else
        {
            int x = (a - b) / 2;
            int n = (a ^ x) == (b + x) ? 1 : 2;

            cout << n << '\n';
            for (int i = 0; i < n; i++)
                cout << (!isSwap ? 'A' : 'B') << ' ' << x << '\n';
        }
    }
}