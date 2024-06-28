#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 10'000

int PosterArea(vector<int>& p)
{
    int x1 = max(p[0], p[4]);
    int y1 = max(p[1], p[5]);
    int x2 = min(p[2], p[6]);
    int y2 = min(p[3], p[7]);

    return (p[2] - p[0]) * (p[3] - p[1]) - max(y2 - y1, 0) * max(x2 - x1, 0);
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        vector<int> p(8);
        for (int i = 0; i < 8; i++)
            cin >> p[i];

        int result = PosterArea(p);
        cout << result << '\n';
    }
}