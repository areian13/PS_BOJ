#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long x, y, p, a, b;
    cin >> x >> y >> p >> a >> b;

    long long result = (p + b * (y - 1)) * x - (a * x * (x - 1) / 2);
    cout << result << '\n';
}