#include <iostream>
#include <array>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x, d;

    friend bool operator<(const Pos& a, const Pos& b)
    {
        return a.d > b.d;
    }
};

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

int EscapeTime(Pos& s, array<int, 26>& time, vector<vector<char>>& map)
{
    int h = map.size();
    int w = map[0].size();

    vector<vector<int>> dist(h, vector<int>(w, INT_MAX));
    dist[s.y][s.x] = 0;

    priority_queue<Pos> PQ;
    PQ.push(s);

    while (!PQ.empty())
    {
        int y = PQ.top().y;
        int x = PQ.top().x;
        int d = PQ.top().d;
        PQ.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= h || nx < 0 || nx >= w)
                continue;

            int nd = d + time[map[ny][nx] - 'A'];
            if (dist[ny][nx] <= nd)
                continue;

            dist[ny][nx] = nd;
            PQ.push({ ny,nx,nd });
        }
    }

    int result = INT_MAX;
    for (int i = 0; i < h; i++)
    {
        result = min(result, dist[i][0]);
        result = min(result, dist[i][w - 1]);
    }
    for (int j = 0; j < w; j++)
    {
        result = min(result, dist[0][j]);
        result = min(result, dist[h - 1][j]);
    }
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int k, w, h;
        cin >> k >> w >> h;

        array<int, 26> time = { 0, };
        for (int i = 0; i < k; i++)
        {
            char c;
            int t;
            cin >> c >> t;

            time[c - 'A'] = t;
        }

        vector<vector<char>> map(h, vector<char>(w));
        Pos s = { -1,-1,INT_MAX };
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];

                if (map[i][j] == 'E')
                    s = { i,j,0 };
            }
        }

        int result = EscapeTime(s, time, map);
        cout << result << '\n';
    }
}