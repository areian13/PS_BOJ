#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long n, m, t, s;
    cin >> n >> m >> t >> s;

    long long p = n + ((n - 1) / 8) * s;
    long long q = m + ((m - 1) / 8) * (t * 2 + s) + t;

    if (p < q) cout << "Zip" << '\n' << p << '\n';
    else cout << "Dok" << '\n' << q << '\n';
}