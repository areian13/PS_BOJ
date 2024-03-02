#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Vote
{
    int cnt, idx;

    friend bool operator>(const Vote& a, const Vote& b)
    {
        if (a.cnt != b.cnt)
            return a.cnt > b.cnt;
        return a.idx < b.idx;
    }
};

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<Vote> vote(m);
    for (int j = 0; j < m; j++)
        vote[j].idx = j + 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int v;
            cin >> v;

            vote[j].cnt += v;
        }
    }
    sort(vote.begin(), vote.end(), greater<Vote>());

    for (int j = 0; j < m; j++)
        cout << vote[j].idx << ' ';
}