#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int BFS(vector<int>& maze)
{
    int n = maze.size();

    vector<int> dist(n, -1);
    dist[0] = 0;

    queue<int> Q;
    Q.push(0);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int i = 1; i <= maze[u]; i++)
        {
            int v = u + i;

            if (v >= n || dist[v] != -1)
                continue;

            dist[v] = dist[u] + 1;
            Q.push(v);
        }
    }
    return dist[n - 1];
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> maze(n);
    for (int i = 0; i < n; i++)
        cin >> maze[i];

    int result = BFS(maze);
    cout << result << '\n';
}