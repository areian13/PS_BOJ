#include <iostream>
#include <vector>
#include <array>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x, t;
};

array<int, 3> dy = { 0,0,1 };
array<int, 3> dx = { 1,-1,0 };

bool CanClear(int k, vector<vector<char>>& map)
{
    int n = map[0].size();
    dx[2] = k;

    vector<vector<bool>> isVisited(2, vector<bool>(n, false));
    isVisited[0][0] = true;

    queue<Pos> Q;
    Q.push({ 0,0,0 });

    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        int t = Q.front().t;
        Q.pop();

        for (int i = 0; i < 3; i++)
        {
            int ny = (y + dy[i]) % 2;
            int nx = x + dx[i];
            int nt = t + 1;

            if (nx >= n)
                return true;
            if (nx <= t || isVisited[ny][nx] || map[ny][nx] == '0')
                continue;

            isVisited[ny][nx] = true;
            Q.push({ ny,nx,nt });
        }
    }
    return false;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<vector<char>> map(2, vector<char>(n));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }
    
    bool result = CanClear(k, map);
    cout << result << '\n';
}