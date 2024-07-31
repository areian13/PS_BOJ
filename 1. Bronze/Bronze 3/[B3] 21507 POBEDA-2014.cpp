#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long result = sqrtl(min(a, b) + min(c, d));
    cout << result << '\n';
}