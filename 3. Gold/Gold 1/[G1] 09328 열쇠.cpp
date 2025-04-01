#include <iostream>
#include <vector>
#include <array>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { -1,0,1,0 };

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int h, w;
        cin >> h >> w;

        vector<vector<char>> map(h, vector<char>(w));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
                cin >> map[i][j];
        }

        array<bool, 26> hasKey = { false, };
        string keys;
        cin >> keys;

        if (keys != "0")
        {
            for (char key : keys)
                hasKey[key - 'a'] = true;
        }

        vector<Pos> starts;
        for (int i = 0; i < w; i++)
        {
            if (map[0][i] != '*')
                starts.push_back({ 0,i });
            if (map[h - 1][i] != '*')
                starts.push_back({ h - 1,i });
        }
        for (int i = 1; i < h - 1; i++)
        {
            if (map[i][0] != '*')
                starts.push_back({ i,0 });
            if (map[i][w - 1] != '*')
                starts.push_back({ i,w - 1 });
        }

        int result = 0;
        vector<vector<bool>> isVisited(h, vector<bool>(w, false));
        for (int i = 0; i < starts.size(); i++)
        {
            if (isVisited[starts[i].y][starts[i].x])
                continue;

            isVisited[starts[i].y][starts[i].x] = true;

            queue<Pos> Q;
            Q.push(starts[i]);

            bool foundKey = false;

            while (!Q.empty())
            {
                int y = Q.front().y;
                int x = Q.front().x;
                Q.pop();

                if (map[y][x] == '$')
                {
                    result++;
                    map[y][x] = '.';
                }
                else if ('A' <= map[y][x] && map[y][x] <= 'Z')
                {
                    if (hasKey[map[y][x] - 'A'])
                        map[y][x] = '.';
                    else
                        continue;
                }
                else if ('a' <= map[y][x] && map[y][x] <= 'z')
                {
                    hasKey[map[y][x] - 'a'] = true;
                    map[y][x] = '.';

                    foundKey = true;
                }

                for (int k = 0; k < 4; k++)
                {
                    int ny = y + dy[k];
                    int nx = x + dx[k];

                    if (ny < 0 || ny >= h || nx < 0 || nx >= w)
                        continue;
                    if (map[ny][nx] == '*' || isVisited[ny][nx])
                        continue;

                    isVisited[ny][nx] = true;
                    Q.push({ ny,nx });
                }

            }
            if (foundKey)
            {
                fill(isVisited.begin(), isVisited.end(), vector<bool>(w, 0));
                i = -1;
            }
        }
        cout << result << '\n';
    }
}