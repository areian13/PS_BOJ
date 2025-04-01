#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Order
{
    int num, indegree;

    friend bool operator<(const Order& a, const Order& b)
    {
        if (a.indegree == 0 && b.indegree == 0)
            return a.num > b.num;
        return a.indegree > b.indegree;
    }
};

int main()
{
    FastIO;

    int n, m;
    cin>> n >> m;

    vector<vector<int>> graph(n);
    vector<Order> order(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin>>a >> b;
        a--, b--;

        order[b].indegree++;
        graph[a].push_back(b);
    }

    priority_queue<Order> PQ;
    for (int i = 0; i < n; i++)
    {
        order[i].num = i;
        PQ.push(order[i]);
    }

    vector<int> result;
    vector<bool> isPushed(n, false);
    while (!PQ.empty())
    {
        int cur = PQ.top().num;
        PQ.pop();

        if (isPushed[cur])
            continue;

        result.push_back(cur + 1);
        isPushed[cur] = true;
        for (int nxt : graph[cur])
        {
            order[nxt].indegree--;

            if (order[nxt].indegree == 0)
                PQ.push(order[nxt]);
        }
    }

    for (int v : result)
        cout << v << ' ';
    cout << '\n';
}