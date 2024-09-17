#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define DEPTH 5

void Spin(vector<vector<int>>& map)
{
    int n = map.size();

    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            temp[j][n - i - 1] = map[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            map[i][j] = temp[i][j];
    }
}

void Move(vector<vector<int>>& map)
{
    int n = map.size();

    vector<vector<bool>> isFixed(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 0)
                continue;

            int y = i;
            while (y > 0 && map[y - 1][j] == 0)
                y--;

            map[y][j] = map[i][j];

            if (y != i)
                map[i][j] = 0;

            if (y > 0 && map[y][j] == map[y - 1][j] && !isFixed[y - 1][j])
            {
                isFixed[y - 1][j] = true;
                map[y - 1][j] *= 2;
                map[y][j] = 0;
            }
        }
    }
}

int MaxBlock(vector<vector<int>>& map)
{
    int n = map.size();

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            result = max(result, map[i][j]);
    }
    return result;
}

int G2048(int k, vector<vector<int>>& map, vector<int>& dp)
{
    int n = map.size();

    int block = MaxBlock(map);
    dp[k] = max(dp[k], block);

    if (k == DEPTH)
        return dp[k];

    if ((block << (DEPTH - k)) <= dp[DEPTH])
        return block;

    vector<vector<int>> temp(n, vector<int>(n));
    int result = dp[k];
    for (int i = 0; i < 4; i++)
    {
        temp = map;

        Move(temp);
        if (temp != map)
            result = max(result, G2048(k + 1, temp, dp));
        Spin(map);
    }
    dp[k + 1] = result;
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }

    vector<int> dp(DEPTH + 1, 0);
    int result = G2048(0, map, dp);
    cout << result << '\n';
}