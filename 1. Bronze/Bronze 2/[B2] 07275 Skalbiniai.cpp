#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<int>> graph(k);
    for (int i = 0; i < k; i++)
    {
        int g;
        cin >> g;

        graph[i].resize(g);
        for (int j = 0; j < g; j++)
        {
            cin >> graph[i][j];
            graph[i][j]--;
        }
    }

    vector<int> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];

    int result = 0;
    for (int i = 0; i < k; i++)
    {
        int sum = 0;
        for (int v : graph[i])
            sum += d[v];
        result += (sum + m - 1) / m;
    }
    cout << result << '\n';
}