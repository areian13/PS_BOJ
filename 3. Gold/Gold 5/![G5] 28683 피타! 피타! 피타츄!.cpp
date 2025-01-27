#include <iostream>
#include <climits>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long n;
    cin >> n;

    int result = 0;
    for (long long a = 1; a * a <= 1e+13; a++)
    {
        if (a * a == n)
        {
            result = INT_MAX;
            break;
        }

        if (a * a < n)
        {
            long long s = sqrt(n - a * a);
            result += (s * s == n - a * a);
        }

        long long b = sqrt(n + a * a);
        result += (b * b == n + a * a);
    }

    if (result == INT_MAX)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}