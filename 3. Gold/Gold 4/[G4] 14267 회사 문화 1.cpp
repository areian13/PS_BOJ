#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void DFS(int cur, vector<vector<int>>& junior, vector<int>& result)
{
    for (auto nxt : junior[cur])
    {
        result[nxt] += result[cur];
        DFS(nxt, junior, result);
    }
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> junior(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int superior;
        cin >> superior;
        junior[max(superior, 0)].push_back(i);
    }

    vector<int> result(n + 1, 0);
    for (int j = 0; j < m; j++)
    {
        int i, w;
        cin >> i >> w;

        result[i] += w;
    }

    DFS(1, junior, result);

    for (int i = 1; i <= n; i++)
        cout << result[i] << ' ';
    cout << '\n';
}