#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, k, x;
    cin >> a >> b >> k >> x;

    int result = 0;
    for (int i = a; i <= b; i++)
        result += (k - x <= i && i <= k + x);

    if (result == 0)
        cout << "IMPOSSIBLE" << '\n';
    else
        cout << result << '\n';
}