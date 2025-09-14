#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsPrime(int n)
{
    if (n <= 1) return false;
    if (n == 2) return true;

    for (int i = 2; i * i <= n; i++)
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

    int first = -1, sum = 0;
    for (int i = m; i <= n; i++)
    {
        if (IsPrime(i))
        {
            first = (first == -1 ? i : first);
            sum += i;
        }
    }

    if (first == -1)
        cout << -1 << '\n';
    else
        cout << sum << '\n' << first << '\n';
}