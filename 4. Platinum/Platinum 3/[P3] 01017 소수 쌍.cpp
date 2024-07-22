#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 2'000

bool CanMatch(int u, vector<bool>& isVisited,
    vector<int>& a, vector<int>& b, vector<vector<int>>& graph)
{
    isVisited[u] = true;

    for (int v : graph[u])
    {
        if (b[v] == -1 ||
            !isVisited[b[v]] && CanMatch(b[v], isVisited, a, b, graph))
        {
            a[u] = v;
            b[v] = u;
            return true;
        }
    }
    return false;
}

void MakeOnesPair(vector<vector<int>>& graph, vector<int>& result)
{
    int n = graph.size();

    for (int v : graph[0])
    {
        vector<int> a(n, -1), b(n, -1);

        a[0] = v;
        b[v] = 0;

        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != -1 || graph[i].empty())
                continue;

            vector<bool> isVisited(n, false);
            isVisited[0] = true;
            cnt += CanMatch(i, isVisited, a, b, graph);
        }

        if (cnt == n / 2)
            result.push_back(v);
    }
}

int main()
{
    FastIO;

    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAX; i++)
    {
        if (!isPrime[i])
            continue;

        for (int j = 2; i * j <= MAX; j++)
            isPrime[i * j] = false;
    }

    int n;
    cin >> n;

    vector<int> list(n);
    for (int i = 0; i < n; i++)
        cin >> list[i];

    vector<vector<int>> graph(n);
    bool isJ = (list[0] % 2 == 0);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (!isPrime[list[i] + list[j]])
                continue;

            bool isA = isJ ^ (list[i] % 2 == 1);
            int u = (isA ? i : j);
            int v = (isA ? j : i);

            graph[u].push_back(v);
        }
    }

    vector<int> result;
    MakeOnesPair(graph, result);

    sort(result.begin(), result.end(),
        [&list](int i, int j)
        {
            return list[i] < list[j];
        }
    );

    if (result.empty())
        cout << -1 << '\n';
    else
    {
        for (int i : result)
            cout << list[i] << ' ';
        cout << '\n';
    }
}