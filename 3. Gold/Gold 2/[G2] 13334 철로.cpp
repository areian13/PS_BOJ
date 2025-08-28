#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Line
{
    int s, e;
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Line> lines(n);
    for (auto& [s, e] : lines)
    {
        cin >> s >> e;
        if (s > e)
            swap(s, e);
    }
    sort(lines.begin(), lines.end(),
        [](const Line& a, const Line& b)
        {
            if (a.e != b.e)
                return a.e < b.e;
            return a.s < b.s;
        }
    );

    int d;
    cin >> d;

    int result = 0;
    int maxS = INT_MIN;
    for (int l = 0, r = 0; r < n;)
    {
        if (maxS >= lines[r].e - d)
        {
            result = max(result, r - l + 1);
            r++;
        }
        else
            l++;

        r += (l >= r);
    }
    cout << result << '\n';
}