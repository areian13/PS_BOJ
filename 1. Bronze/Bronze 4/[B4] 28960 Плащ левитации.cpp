#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanHang(int h, int l, int a, int b)
{
    if (a > l && b > l)
        return false;

    if (a <= l && b <= l)
        return min(a, b) / 2. <= h;
    if (a <= l)
        return b / 2. <= h;
    return a / 2. <= h;
}

int main()
{
    FastIO;

    int h, l, a, b;
    cin >> h >> l >> a >> b;

    string result = CanHang(h, l, a, b) ? "YES" : "NO";
    cout << result << '\n';
}