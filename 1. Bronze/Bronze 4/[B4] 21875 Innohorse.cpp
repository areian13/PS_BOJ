#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    int x = abs(a[0] - b[0]);
    int y = abs(a[1] - b[1]);
    if (x > y)
        swap(x, y);

    cout << x << ' ' << y << '\n';
}