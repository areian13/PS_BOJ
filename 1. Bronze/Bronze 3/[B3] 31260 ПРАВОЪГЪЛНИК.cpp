#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long x, y, d;
    cin >> x >> y >> d;

    long long l = x * 100 + y;
    long long a = (l / 2 - d) / 2;
    long long b = a + d;

    cout << b / 100 << ' ' << b % 100 << '\n';
    cout << a / 100 << ' ' << a % 100 << '\n';
}