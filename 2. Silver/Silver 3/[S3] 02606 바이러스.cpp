#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> net(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        net[a].push_back(b);
        net[b].push_back(a);
    }

    vector<bool> isInfected(n + 1, false);
    isInfected[1] = true;

    queue<int> Q;
    Q.push(1);

    int result = 0;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : net[u])
        {
            if (isInfected[v])
                continue;

            result++;
            isInfected[v] = true;
            Q.push(v);
        }
    }

    cout << result << '\n';
}