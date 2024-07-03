#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int l, r, a;
    cin >> l >> r >> a;

    int result = min({ l + a,r + a,(l + r + a) / 2 }) * 2;
    cout << result << '\n';
}