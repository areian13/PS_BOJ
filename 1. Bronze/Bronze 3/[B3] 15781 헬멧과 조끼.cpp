#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    int maxH = 0;
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;

        maxH = max(maxH, h);
    }

    int maxJ = 0;
    for (int i = 0; i < m; i++)
    {
        int j;
        cin >> j;

        maxJ = max(maxJ, j);
    }

    int result = maxH + maxJ;
    cout << result << '\n';
}