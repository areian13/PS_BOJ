#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanWant(vector<int>& c, vector<int>& w)
{
    priority_queue<int> pq(c.begin(), c.end());
    for (int v : w)
    {
        if (pq.top() < v)
            return false;

        pq.push(pq.top() - v);
        pq.pop();
    }
    return true;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> c(n), w(m);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < m; i++)
        cin >> w[i];

    bool result = CanWant(c, w);
    cout << result << '\n';
}