#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Segment
{
    int s, e;
};

int Rail(int d, vector<Segment>& segments)
{
    int n = segments.size();
    sort(segments.begin(), segments.end(),
        [](const Segment& a, const Segment& b)
        {
            if (a.e != b.e) return a.e < b.e;
            return a.s < b.s;
        }
    );

    priority_queue<int, vector<int>, greater<int>> pq;
    int result = 0;
    for (auto& [s, e] : segments)
    {
        while (!pq.empty() && pq.top() < e - d)
            pq.pop();
        if (e - s > d)
            continue;

        pq.push(s);
        result = max(result, (int)pq.size());
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Segment> segments(n);
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        if (s > e) swap(s, e);
        segments[i] = { s,e };
    }

    int d;
    cin >> d;

    int result = Rail(d, segments);
    cout << result << '\n';
}