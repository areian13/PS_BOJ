#include <iostream>
#include <vector>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Node
{
    int d, r, c;
};

array<int, 6> dd = { 0,0,1,0,0,-1 };
array<int, 6> dr = { 0,1,0,0,-1,0 };
array<int, 6> dc = { 1,0,0,-1,0,0 };

void BFS(int k, int i, int j,
    vector<vector<vector<bool>>>& isVisited,
    vector<vector<char>>& map)
{
    int n = isVisited[0].size();
    int m = isVisited[0][0].size();

    queue<Node> Q;
    Q.push({ k,i,j });
    isVisited[k][i][j] = true;

    while (!Q.empty())
    {
        auto [d, r, c] = Q.front();
        Q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nd = d + dd[i];
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nd < 0 || nd >= 2 || nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            if (isVisited[nd][nr][nc])
                continue;

            if (r / 2 == nr / 2 && c / 2 == nc / 2)
            {
                if (i % 3 == map[r / 2][c / 2])
                {
                    isVisited[nd][nr][nc] = true;
                    Q.push({ nd,nr,nc });
                }
            }
            else if (i % 3 != 2)
            {
                isVisited[nd][nr][nc] = true;
                Q.push({ nd,nr,nc });
            }
        }
    }
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;

            map[i][j] = (c == 'H' ? 0 : (c == 'I' ? 1 : 2));
        }
    }

    vector isVisited(2, vector(n * 2, vector(m * 2, false)));
    int result = 0;
    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < n * 2; i++)
        {
            for (int j = 0; j < m * 2; j++)
            {
                if (isVisited[k][i][j])
                    continue;

                result++;
                BFS(k, i, j, isVisited, map);
            }
        }
    }
    cout << result << '\n';
}