#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Lecture
{
    int start, end;
    bool operator<(Lecture b) const
    {
        if (start == b.start)
            return end < b.end;
        return start < b.start;
    }
    bool operator>(Lecture b) const
    {
        if (start == b.start)
            return end > b.end;
        return start > b.start;
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Lecture> lectures(n);
    for (int i = 0; i < n; i++)
    {
        int num, start, end;
        cin >> num >> start >> end;
        lectures[i] = { start, end };
    }
    sort(lectures.begin(), lectures.end());

    priority_queue<Lecture, vector<Lecture>, greater<Lecture>> PQ;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (!PQ.empty())
        {
            if (PQ.top().start > lectures[i].start)
                result++;
            else
                PQ.pop();
        }
        else
            result++;

        PQ.push({ lectures[i].end,lectures[i].start });
    }
    cout << result << '\n';
}