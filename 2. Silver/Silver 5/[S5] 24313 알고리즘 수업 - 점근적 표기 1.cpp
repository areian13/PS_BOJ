#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;

    bool result = (a1 * n0 + a0 <= c * n0) && (c >= a1);
    cout << result << '\n';
}