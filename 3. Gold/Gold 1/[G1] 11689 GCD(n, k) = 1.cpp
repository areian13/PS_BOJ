#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

typedef long long ll;

ll phi(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i != 0)
            continue;

        result -= result / i;
        while (n % i == 0)
            n /= i;
    }
    if (n > 1)
        result -= result / n;

    return result;
}

int main()
{
    FastIO;

    ll n;
    cin >> n;

    ll result = phi(n);
    cout << result << '\n';
}