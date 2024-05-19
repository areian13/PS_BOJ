#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX_HEIGHT 20

struct Pos
{
    int y, x, t;
};

int dy(int y, int i)
{
    if (i == 0)
        return y;
    if (i == 1)
        return y + 1;
    if (i == 2)
        return min(y * 2 + 1, MAX_HEIGHT - 1);
    if (i == 3)
        return y - 1;
    return i - 4;
}

int MinT(int k, vector<vector<bool>>& isTree)
{
    int n = isTree[0].size();

    vector<vector<int>> dist(MAX_HEIGHT, vector<int>(n, INT_MAX));

    queue<Pos> Q;
    Q.push({ 0,-1,0 });

    int result = INT_MAX;
    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        int t = Q.front().t;
        Q.pop();

        int nx = x + 1;
        if (nx == n)
        {
            result = min(result, t);
            continue;
        }

        for (int i = 0; i < 4 + MAX_HEIGHT; i++)
        {
            int ny = dy(y, i);
            int nt = t + (i >= 4);

            if (ny < 0 || ny >= MAX_HEIGHT)
                continue;
            if (isTree[ny][nx] || dist[ny][nx] <= nt)
                continue;

            dist[ny][nx] = nt;
            Q.push({ ny,nx,nt });
        }
    }
    if (result > k)
        return -1;
    return result;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<vector<bool>> isTree(MAX_HEIGHT, vector<bool>(n, true));
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        for (int j = 0; j < m; j++)
        {
            int h;
            cin >> h;
            h--;

            isTree[h][i] = false;
        }
    }

    int result = MinT(k, isTree);
    cout << result << '\n';
}