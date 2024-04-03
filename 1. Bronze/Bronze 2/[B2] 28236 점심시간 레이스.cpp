#include <iostream>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    int minDist = INT_MAX;
    int result = -1;
    for (int i = 0; i < k; i++)
    {
        int y, x;
        cin >> y >> x;

        int dist = y + (m - x);
        if (dist < minDist)
        {
            minDist = dist;
            result = i + 1;
        }
    }
    cout << result << '\n';
}