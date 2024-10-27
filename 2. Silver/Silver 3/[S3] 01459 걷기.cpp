#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long MinTime(int x, int y, int w, int s)
{
    long long M = max(x, y);
    long long m = min(x, y);

    if (w * 2 <= s)
        return (long long)(x + y) * w;
    if (w <= s)
        return ((M - m) * w) + (m * s);
    return (m * s) + ((M - m) / 2 * 2 * s) + ((M - m) % 2 * w);
}

int main()
{
    FastIO;

    int x, y, w, s;
    cin >> x >> y >> w >> s;

    long long result = MinTime(x, y, w, s);
    cout << result << '\n';
}