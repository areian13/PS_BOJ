#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsPrime(int n)
{
    if (n <= 1)
        return false;

    int k = sqrt(n) + 0.5;
    for (int i = 2; i <= k; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int m, n;
    cin >> m >> n;

    int sum = 0;
    int min = 0;

    for (int p = m; p <= n; p++)
    {
        if (!IsPrime(p))
            continue;

        sum += p;
        min = (min == 0 ? p : min);
    }

    if (sum == 0)
        cout << -1 << '\n';
    else
        cout << sum << '\n' << min << '\n';
}