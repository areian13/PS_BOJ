#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    if (x > y)
        swap(a, b), swap(x, y);

    int p1 = a * x + b * y;
    int p2 = c * y * 2;
    int p3 = c * x * 2 + (y - x) * b;
    int result = min({ p1,p2,p3 });
    cout << result << '\n';
}