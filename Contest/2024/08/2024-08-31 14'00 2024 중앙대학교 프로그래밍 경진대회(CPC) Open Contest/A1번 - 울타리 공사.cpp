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

    int minX = INT_MAX;
    int minY = INT_MAX;
    int maxX = INT_MIN;
    int maxY = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        minX = min(minX, a);
        minY = min(minY, b);
        maxX = max(maxX, c);
        maxY = max(maxY, d);

        int result = (maxX - minX) * 2 + (maxY - minY) * 2;
        cout << result << '\n';
    }
}