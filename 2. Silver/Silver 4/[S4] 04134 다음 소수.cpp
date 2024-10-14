#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsPrime(long long n)
{
    if (n <= 1)
        return false;

    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

long long NextPrime(long long n)
{
    while (!IsPrime(n))
        n++;
    return n;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        long long n;
        cin >> n;

        long long result = NextPrime(n);
        cout << result << '\n';
    }
}