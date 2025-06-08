#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        int p;
        cin >> p;

        int s = (p + 1) / 2 * 2;
        s -= (s == p);
        array<int, 3> result = { s,n - s + 1,n - p + 1 };
        sort(result.begin(), result.end());
        for (int i = 0; i < 3; i++)
            cout << result[i] << ' ';
        cout << '\n';
    }
}