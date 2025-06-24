#include <iostream>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int v = a + b + c;
        if (v >= 512)
            result = min(result, v);
    }

    if (result == INT_MAX)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}