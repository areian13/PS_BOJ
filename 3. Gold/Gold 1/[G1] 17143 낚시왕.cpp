#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dr = { -1,1,0,0 };
array<int, 4> dc = { 0,0,1,-1, };

int RevDir(int d)
{
    if (d == 0)
        return 1;
    if (d == 1)
        return 0;
    if (d == 2)
        return 3;
    return 2;
}

struct Shark
{
    int r, c, s, d, z;
    bool moved = false;

    Shark() : Shark(-1, -1, 0, 0, -1) {}
    Shark(int r, int c, int s, int d, int z) : r(r), c(c), s(s), d(d), z(z) {}

    void Move(int n, int m)
    {
        int p = (d < 2 ? n : m);
        int k = s % ((p - 1) * 2);
        for (int i = 0; i < k; i++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
            {
                d = RevDir(d);
                nr = r + dr[d];
                nc = c + dc[d];
            }

            r = nr;
            c = nc;
        }
    }
};

void MoveSharks(vector<vector<vector<Shark>>>& map)
{
    int n = map.size();
    int m = map[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j].empty() || map[i][j][0].moved)
                continue;

            Shark me = map[i][j][0];
            map[i][j].erase(map[i][j].begin());

            me.Move(n, m);
            me.moved = true;
            map[me.r][me.c].push_back(me);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j].empty())
                continue;

            sort(map[i][j].begin(), map[i][j].end(),
                [](Shark& a, Shark& b)
                {
                    return a.z > b.z;
                }
            );

            map[i][j].erase(map[i][j].begin() + 1, map[i][j].end());
            map[i][j][0].moved = false;
        }
    }
}

void Print(vector<vector<vector<Shark>>>& map)
{
    int n = map.size();
    int m = map[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j].empty())
                cout << '-';
            else
                cout << map[i][j][0].z;
        }
        cout << '\n';
    }
    cout << '\n';
}

int main()
{
    FastIO;

    int r, c, m;
    cin >> r >> c >> m;

    vector<vector<vector<Shark>>> map(r, vector<vector<Shark>>(c));
    for (int i = 0; i < m; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        r--, c--, d--;

        map[r][c].push_back(Shark(r, c, s, d, z));
    }

    int result = 0;
    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < r; i++)
        {
            if (map[i][j].empty())
                continue;

            result += map[i][j][0].z;
            map[i][j].pop_back();
            break;
        }

        MoveSharks(map);
    }
    cout << result << '\n';
}