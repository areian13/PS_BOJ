#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

int nthZero = 0;
vector<int> zeroSize;

void BFS(int i, int j, vector<vector<int>>& map, vector<vector<int>>& zeroNum, vector<vector<bool>>& isVisited)
{
    int n = map.size();
    int m = map[0].size();

    isVisited[i][j] = true;

    queue<Pos> Q;
    Q.push({ i,j });

    zeroNum[i][j] = nthZero;
    int cnt = 1;

    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();

        for (int k = 0; k < 4; k++)
        {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (map[ny][nx] == 1 || isVisited[ny][nx])
                continue;

            isVisited[ny][nx] = true;
            zeroNum[ny][nx] = nthZero;
            Q.push({ ny,nx });
            cnt++;
        }
    }
    zeroSize.push_back(cnt);
    nthZero++;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        string num;
        cin >> num;

        for (int j = 0; j < m; j++)
            map[i][j] = (num[j] - '0');
    }

    vector<vector<int>> zeroNum(n, vector<int>(m));
    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1 || isVisited[i][j])
                continue;

            BFS(i, j, map, zeroNum, isVisited);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                cout << 0;
                continue;
            }

            set<int> Set;
            for (int k = 0; k < 4; k++)
            {
                int ny = i + dy[k];
                int nx = j + dx[k];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                    continue;
                if (map[ny][nx] == 1 || !isVisited[ny][nx])
                    continue;
                Set.insert(zeroNum[ny][nx]);
            }
            for (int value : Set)
                map[i][j] += zeroSize[value];

            cout<< map[i][j] % 10;
        }
        cout << '\n';
    }
}