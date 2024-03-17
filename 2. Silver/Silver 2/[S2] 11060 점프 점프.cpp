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
        int cur = Q.front();
        Q.pop();

        for (int i = 1; i <= maze[cur]; i++)
        {
            int nxt = cur + i;

            if (nxt >= n || dist[nxt] != -1)
                continue;

            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
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