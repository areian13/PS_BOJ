#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

typedef unsigned long long ull;

ull Power(ull a, ull b, ull mod)
{
    ull result = 1;
    a %= mod;
    while (b > 0)
    {
        if (b % 2 == 1)
            result = (result * a) % mod;
        b /= 2;
        a = (a * a) % mod;
    }
    return result;
}

bool Miller(ull n, ull a)
{
    if (n % a == 0)
        return true;

    ull d = n - 1;
    while (true)
    {
        ull temp = Power(a, d, n);
        if (d % 2 == 1)
            return (temp == 1 || temp == n - 1);
        else if (temp == n - 1)
            return true;
        d /= 2;
    }
}

bool IsPrime(ull n)
{
    static vector<ull> base = { 2,7,61 };
    for (ull a : base)
    {
        if (!Miller(n, a))
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        ull a;
        cin >> a;

        result += IsPrime(a * 2 + 1);
    }
    cout << result << '\n';
}