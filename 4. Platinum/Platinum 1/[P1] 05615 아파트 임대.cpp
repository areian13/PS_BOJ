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
    if (n <= 1)
        return false;
    if (n == 2 || n == a)
        return true;

    ull k = n - 1;
    while (true)
    {
        ull temp = Power(a, k, n);
        if (temp == n - 1)
            return true;
        if (k % 2 == 1)
            return temp == 1 || temp == n - 1;
        k /= 2;
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