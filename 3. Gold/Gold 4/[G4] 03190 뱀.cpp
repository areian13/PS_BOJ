#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

enum State
{
    EMPTY,
    SNAKE,
    APPLE
};

struct Pos
{
    int y, x;
};

int Dummy(vector<pair<int, char>>& cmds, vector<vector<int>>& map)
{
    int n = map.size();

    int y = 0;
    int x = 0;
    int d = 0;

    map[y][x] = State::SNAKE;
    queue<Pos> Q;
    Q.push({ y,x });

    int result = 0;
    for (auto& cmd : cmds)
    {
        int k = cmd.first;
        for (int i = result; i < k; i++)
        {
            result++;

            y += dy[d];
            x += dx[d];

            if (y < 0 || y >= n || x < 0 || x >= n)
                return result;
            if (map[y][x] == State::SNAKE)
                return result;

            if (map[y][x] != State::APPLE)
            {
                int ry = Q.front().y;
                int rx = Q.front().x;
                Q.pop();

                map[ry][rx] = State::EMPTY;
            }

            map[y][x] = State::SNAKE;
            Q.push({ y,x });
        }

        d = (d + (cmd.second == 'D' ? 1 : 3)) % 4;
    }

    return result;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<vector<int>> map(n, vector<int>(n, State::EMPTY));
    for (int i = 0; i < k; i++)
    {
        int y, x;
        cin >> y >> x;
        y--, x--;

        map[y][x] = State::APPLE;
    }

    int l;
    cin >> l;

    vector<pair<int, char>> cmds(l + 1);
    for (auto& cmd : cmds)
        cin >> cmd.first >> cmd.second;
    cmds[l] = { INT_MAX,'E' };

    int result = Dummy(cmds, map);
    cout << result << '\n';
}