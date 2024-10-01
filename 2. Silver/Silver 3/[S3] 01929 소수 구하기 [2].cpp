#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsPrime(int n)
{
    if (n <= 1)
        return false;

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

    for (int i = m; i <= n; i++)
    {
        if (IsPrime(i))
            cout << i << '\n';
    }
}