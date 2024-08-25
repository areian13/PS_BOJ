#include <iostream>
#include <vector>
#include <array>
#include <numeric>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 2> SwapScore(int n, int m, vector<int>& s)
{
    int tSum = accumulate(s.begin(), s.begin() + n, 0);
    int hSum = accumulate(s.begin() + n, s.end(), 0);

    array<int, 2> result = { -1,-1 };
    int minSum = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < n + m; j++)
        {
            int ntSum = tSum - s[i] + s[j];
            int nhSum = hSum - s[j] + s[i];

            if (ntSum != nhSum)
                continue;
            if (minSum > s[i] + s[j])
            {
                result = { s[i],s[j] };
                minSum = s[i] + s[j];
            }
        }
    }
    return result;
}

int main()
{
    FastIO;

    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        vector<int> s(n + m);
        for (int i = 0; i < n + m; i++)
            cin >> s[i];

        array<int, 2> result = SwapScore(n, m, s);
        if (result[0] == -1)
            cout << -1 << '\n';
        else
            cout << result[0] << ' ' << result[1] << '\n';
    }
}