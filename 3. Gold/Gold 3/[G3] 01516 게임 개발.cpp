#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> time(n + 1), indegree(n + 1, 0), result(n + 1);
    vector<vector<int>> edge(n + 1);
    queue<int> Q;
    for (int i = 1; i <= n; i++)
    {
        cin >> time[i];
        while (true)
        {
            int pre;
            cin >> pre;

            if (pre == -1)
                break;

            indegree[i]++;
            edge[pre].push_back(i);
        }
        if (indegree[i] == 0)
        {
            result[i] = time[i];
            Q.push(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int cur = Q.front();
        Q.pop();

        for (int nxt : edge[cur])
        {
            result[nxt] = max(result[nxt], result[cur] + time[nxt]);
            if (--indegree[nxt] == 0)
                Q.push(nxt);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << result[i] << '\n';
}