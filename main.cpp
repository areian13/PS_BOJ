#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        int result = ((n % 10'000) * 3897 + (n / 100'000) * (n / 100'000)) % 10'000;
        cout << result << '\n';
    }
}