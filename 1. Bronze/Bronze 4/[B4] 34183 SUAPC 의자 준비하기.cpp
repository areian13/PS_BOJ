#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int r = max(n * 3 - m, 0);
    if (r == 0)
        cout << 0 << '\n';
    else
        cout << r * a + b << '\n';
}