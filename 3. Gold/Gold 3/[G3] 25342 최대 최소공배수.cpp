#include <iostream>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        long long n;
        cin >> n;

        long long result = 0;
        for (int i = n - 1; i <= n; i++)
        {
            for (int j = n - 2; j < i; j++)
            {
                for (int k = n - 3; k < j; k++)
                    result = max(result, lcm(lcm(1LL * i, j), k));
            }
        }

        cout << result << '\n';
    }
}