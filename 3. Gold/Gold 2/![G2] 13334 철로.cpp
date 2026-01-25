#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Line
{
    int s, e;
};
struct Event
{
    int p, idx, isEnd;

    friend bool operator < (const Event& a, const Event& b)
    {
        if (a.p != b.p) return a.p < b.p;
        return a.isEnd < b.isEnd;
    }
};

int Rail(int d, vector<Line>& lines)
{
    int n = lines.size();

    vector<Event> events(n * 2);
    for (int i = 0; i < n; i++)
    {
        events[i * 2] = { lines[i].s,i,false };
        events[i * 2 + 1] = { lines[i].e,i,true };
    }
    sort(events.begin(), events.end());

    int result = 0;
    queue<int> q;
    for (auto& [p, idx, isEnd] : events)
    {
        while (q.front() < p - d)
            q.pop();

        auto& [s, e] = lines[idx];

        if (e - s > d) continue;
        if (!isEnd)
            q.push(p);
        else if(e - d >)
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Line> lines(n);
    for (auto& [s, e] : lines)
        cin >> s >> e;

    int d;
    cin >> d;

    int result = Rail(d, lines);
    cout << result << '\n';
}