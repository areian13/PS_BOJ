#include <iostream>
#include <array>
#include <queue>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 3

int Identify(array<array<char, SIZE>, SIZE>& map)
{
    int result = 0;
    int bit = 1;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            result += bit * (map[i][j] == '*');
            bit <<= 1;
        }
    }
    return result;
}

bool IsWhiteBoard(array<array<char, SIZE>, SIZE>& map)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (map[i][j] == '*')
                return false;
        }
    }
    return true;
}

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

void Click(int y, int x, array<array<char, SIZE>, SIZE>& map)
{
    map[y][x] = (map[y][x] == '*' ? '.' : '*');
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= SIZE || nx < 0 || nx >= SIZE)
            continue;

        map[ny][nx] = (map[ny][nx] == '*' ? '.' : '*');
    }
}

int BFS(array<array<char, SIZE>, SIZE>& s)
{
    unordered_map<int, int> dist;
    dist[Identify(s)] = 1;

    queue<array<array<char, SIZE>, SIZE>> Q;
    Q.push(s);

    while (!Q.empty())
    {
        array<array<char, SIZE>, SIZE> cur = Q.front();
        Q.pop();

        if (IsWhiteBoard(cur))
            return dist[Identify(cur)] - 1;

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                array<array<char, SIZE>, SIZE> nxt = cur;
                Click(i, j, nxt);

                if (dist[Identify(nxt)] != 0)
                    continue;

                dist[Identify(nxt)] = dist[Identify(cur)] + 1;
                Q.push(nxt);
            }
        }
    }
    return -1;
}

int main()
{
    FastIO;

    int p;
    cin >> p;

    while (p--)
    {
        array<array<char, SIZE>, SIZE> map;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
                cin >> map[i][j];
        }

        int result = BFS(map);
        cout << result << '\n';
    }
}