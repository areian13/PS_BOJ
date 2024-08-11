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

    int minY = INT_MAX;
    int maxY = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        minY = min(minY, y);
        maxY = max(maxY, y);
    }

    int result = maxY - minY;
    cout << result << '\n';
}