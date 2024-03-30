#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Horse
{
    int num;
    int dir;
};

struct HorseSet
{
    vector<Horse> horse;
    int dir;

    void Init()
    {
        if (!horse.empty())
            dir = horse[0].dir;
    }
    void Reverse()
    {
        reverse(horse.begin(), horse.end());
        dir = horse[0].dir;
    }
    void Add(HorseSet& other)
    {
        horse.insert(horse.end(), other.horse.begin(), other.horse.end());
    }
    void Clear()
    {
        horse.clear();
    }
};

struct Grid
{
    int color;
    HorseSet horseSet;
};

struct Pos
{
    int y, x;
};

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<vector<Grid>> map(n, vector<Grid>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j].color;
    }

    vector<Pos> pos(k);
    for (int i = 0; i < k; i++)
    {
        int y, x, d;
        cin >> y >> x >> d;
        y--, x--, d--;

        pos[i] = { y,x };

        HorseSet& horseSet = map[y][x].horseSet;
        horseSet.horse.push_back({ i,d });
        horseSet.Init();
    }


}