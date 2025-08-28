#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n, k;
        cin >> n >> k;

        if (n == 0 && k == 0)
            break;

        int maxS = 1, minB = k;
        for (int i = 0; i < n; i++)
        {
            int x;
            string t;
            cin >> x >> t;

            if (t == "SAFE")
                maxS = max(maxS, x);
            else
                minB = min(minB, x);
        }

        cout << maxS + 1 << ' ' << minB - 1 << '\n';
    }
}