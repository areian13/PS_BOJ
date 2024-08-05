#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long d, m, w, i, j, k;
    cin >> d >> m >> w >> i >> j >> k;

    long long day = m * d * (k - 1) + d * (j - 1) + (i - 1);
    char result = 'a' + (day % w);
    cout << result << '\n';
}