#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long k, a, x, b, y;
    cin >> k >> a >> x >> b >> y;

    long long f = max(k - a, 0LL) * x + max(k - b - a, 0LL) * y;
    long long s = max(k - a - b, 0LL) * x + max(k - b, 0LL) * y;
    long long result = max(f, s);
    cout << result << '\n';
}
