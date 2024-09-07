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
    for (int i = 0; i < n; i++)
        cin >> lines[i].s >> lines[i].e;

    sort(lines.begin(), lines.end(),
        [](const Line& a, const Line& b)
        {
            if (a.s != b.s)
                return a.s < b.s;
            return a.e < b.e;
        }
    );

    Line cur = { INT_MIN,INT_MIN };
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (lines[i].s > cur.e)
        {
            result += (cur.e - cur.s);
            cur = lines[i];
        }
        else
            cur.e = max(cur.e, lines[i].e);
    }
    result += (cur.e - cur.s);

    cout << result << '\n';
}