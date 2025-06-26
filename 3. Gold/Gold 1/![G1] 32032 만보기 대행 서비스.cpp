#include <iostream>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long MinDist(long long l, long long r, long long d)
{
    if (l >= 0)
        return r * 2 + d;
    l = -l;
    if (r <= 0)
        return l * 2 + d;

    if (l > r)
        swap(l, r);

    long long result = (d / (l + r)) * (l + r);
    d %= (l + r);

    long long a = (l + r + d) * 2;
    long long b = l * 4 + r * 2 + d;
    result += min(a, b);
    return result;
}

int main()
{
    FastIO;

    int n, d;
    cin >> n >> d;

    int l = INT_MAX, r = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        l = min(l, x);
        r = max(r, x);
    }

    long long result = MinDist(l, r, d);
    cout << result << '\n';
}