#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);

    int result = (b - a + 1) + (d - c + 1);
    if (c <= b && a <= d)
        result -= min(b, d) - max(a, c) + 1;
    cout << result << '\n';
}