#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin>>n;

    vector<string> people(n);
    for (int i = 0; i < n; i++)
        cin>>people[i];

    int m;
    cin >> m;

    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> indegree;
    for (int i = 0; i < m; i++)
    {
        string x, y;
        cin>>x >> y;

        indegree[x]++;
        graph[y].push_back(x);
    }

    queue<string> Q;
    for (auto& it : graph)
    {
        if (indegree[it.first] == 0)
            Q.push(it.first);
    }

    unordered_map<string, int> dist;
    while (!Q.empty())
    {
        string cur = Q.front();
        Q.pop();

        for (string nxt : graph[cur])
        {

        }
    }
}