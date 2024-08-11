#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    long long result = max(min(b, n - c) - max(a, n - d) + 1, 0ll);
    cout << result << '\n';
}