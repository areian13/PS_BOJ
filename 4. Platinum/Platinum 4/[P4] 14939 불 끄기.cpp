#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;
const int MAX = 10;

vector<int> dr = { 0,0,1,0,-1 };
vector<int> dc = { 0,1,0,-1,0 };

void Toggle(int r, int c, vector<vector<bool>>& map)
{
    for (int i = 0; i < 5; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= MAX || nc < 0 || nc >= MAX)
            continue;

        map[nr][nc] = !map[nr][nc];
    }
}
bool Check(vector<vector<bool>>& map)
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
            if (map[i][j]) return false;
    }
    return true;
}

int main()
{
    FastIO;

    vector<vector<bool>> map(MAX, vector<bool>(MAX, false));
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            char c;
            cin >> c;
            map[i][j] = (c == 'O');
        }
    }

    int result = INF;
    for (int t = 0; t < (1 << MAX); t++)
    {
        auto temp = map;
        int cnt = 0;
        for (int j = 0; j < MAX; j++)
        {
            if (t & (1 << j))
                Toggle(0, j, temp), cnt++;
        }

        for (int i = 1; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                if(temp[i - 1][j])
                    Toggle(i, j, temp), cnt++;
            }
        }

        if (Check(temp))
            result = min(result, cnt);
    }

    if (result == INF) cout << -1 << '\n';
    else cout << result << '\n';
}