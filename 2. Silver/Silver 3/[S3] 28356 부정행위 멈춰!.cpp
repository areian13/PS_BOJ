#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    int k = 4;
    if (n == 1 && m == 1)
        k = 1;
    else if (n < 2 || m < 2)
        k = 2;

    cout << k << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int result = min(2 * (i % 2) + (j % 2) + 1, k);
            cout << result << '\n';
        }
        cout << '\n';
    }
}