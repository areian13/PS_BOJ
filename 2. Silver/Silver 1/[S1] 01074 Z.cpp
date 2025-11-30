#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Z(int k, int r, int c)
{
    if (k == 1)
        return 0;
    k >>= 1;

    int p = (r >= k) * 2 + (c >= k);
    r %= k;
    c %= k;
    return Z(k, r, c) + k * k * p;
}

int main()
{
    FastIO;

    int n, r, c;
    cin >> n >> r >> c;

    int result = Z(1 << n, r, c);
    cout << result << '\n';
}