#ifdef ONLINE_JUDGE
#define _128d  __int128
#else
#define _128d long long
#endif

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <cfloat>
#include <cstring>
#include <random>
#include <type_traits>
#include <numeric>
#include <functional>

#define Endl << "\n"
#define endL << "\n" <<
#define Cout cout <<
#define COUT cout << "OUT: " <<
#define Cin cin >>
#define fspc << " "
#define spc << " " <<
#define Enter cout << "\n"
#define if if
#define elif else if
#define else else
#define For(n) for(int i = 0; i < n; i++)
#define Forj(n) for(int j = 0; j < n; j++)
#define Foro(n) for(int i = 1; i <= n; i++)
#define Forjo(n) for(int j = 1; j <= n; j++)
#define between(small, middle, big) (small < middle && middle < big)
#define among(small, middle, big) (small <= middle && middle <= big)
#define stoe(container) container.begin(), container.end()
#define lf(d) Cout fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI 3.14159265359

typedef long long LLONG;
typedef unsigned long long ULLONG;
typedef unsigned int UINT;
typedef long double LDOUBLE;

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec)
{
    for (T& value : vec)
        os << value << ' ';
    return os;
}

template <typename T, size_t N>
ostream& operator<<(ostream& os, array<T, N>& vec)
{
    for (T& value : vec)
        os << value << ' ';
    return os;
}

struct Pos
{
    int y, x;

    friend bool operator==(const Pos& a, const Pos& b)
    {
        return a.y == b.y && a.x == b.x;
    }
};

namespace std
{
    template <>
    struct hash<Pos>
    {
        size_t operator()(const Pos& p) const
        {
            size_t h1 = hash<int>{}(p.y);
            size_t h2 = hash<int>{}(p.x);
            return h1 ^ (h2 << 1);
        }
    };
}

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

int n, m;
vector<vector<char>> grid(n, vector<char>(m));

struct Monster
{
    string name;
    int w, a, h, maxH, e;
    bool isBoss;
};
unordered_map<Pos, Monster> monster;

struct Accessary
{
    char type;
    string effect;
};
unordered_map<Pos, Accessary> accessay;

struct Player
{
    int level;
    int curHP;
    int maxHP;
    int attack;
    int weapon;
    int defence;
    int armor;
    int curEXP;
    int maxEXP;

    int turn;
    bool isDead;
    string endingComment;

    bool isKilledBoss;

    int cntAccessory;
    unordered_map<string, bool> hasAccessory;

    Pos curPoint;
    Pos spawnPoint;

    Player()
    {
        level = 1;
        curHP = maxHP = 20;
        attack = 2;
        weapon = 0;
        defence = 2;
        armor = 0;
        curEXP = 0;
        maxEXP = level * 5;

        turn = 0;
        isDead = false;
        endingComment = "Press any key to continue.";

        isKilledBoss = false;

        cntAccessory = 0;
    }

    int DirIdx(char dir)
    {
        string rdlu = "RDLU";
        For(4)
        {
            if (dir == rdlu[i])
                return i;
        }
        return -1;
    }

    void Move(char dir)
    {
        int dirIdx = DirIdx(dir);
        int ny = curPoint.y + dy[dirIdx];
        int nx = curPoint.x + dx[dirIdx];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            return;
        if (grid[ny][nx] == '#')
            return;

        curPoint = { ny,nx };
    }
    void StepSpikeTrap()
    {
        Damaged(hasAccessory["DX"] ? 1 : 5, true);
        if (curHP <= 0)
        {
            Die("SPIKE TRAP");
            if (hasAccessory["RE"])
                Revive();
        }
    }
    void Die(string s)
    {
        curHP = 0;
        isDead = true;
        endingComment = "YOU HAVE BEEN KILLED BY " + s + "..";
    }
    void Revive()
    {
        endingComment = "Press any key to continue.";
        isDead = false;
        curHP = maxHP;
        curPoint = spawnPoint;
        hasAccessory["RE"] = false;
        cntAccessory--;
    }
    void Damaged(int damage, bool isAbsolute)
    {
        int resultDamage = (isAbsolute ? damage : max(1, damage - (defence + armor)));
        curHP -= resultDamage;
    }
    void GetItem(int y, int x)
    {
        Accessary item = accessay[{y, x}];
        if (item.type == 'W')
            weapon = stoi(item.effect);
        elif(item.type == 'A')
            armor = stoi(item.effect);
        elif(item.type == 'O')
        {
            if (cntAccessory < 4 && !hasAccessory[item.effect])
            {
                hasAccessory[item.effect] = true;
                cntAccessory++;
            }
        }
        grid[y][x] = '.';
    }
    void GetEXP(int exp)
    {
        curEXP += exp * (hasAccessory["EX"] ? 1.2 : 1.0);
        if (curEXP >= maxEXP)
        {
            level++;
            maxEXP = level * 5;
            curEXP = 0;

            maxHP += 5;
            attack += 2;
            defence += 2;
            curHP = maxHP;
        }
    }
    void FightMonster(int y, int x)
    {
        Monster mob = monster[{y, x}];

        if (mob.isBoss && hasAccessory["HU"])
            curHP = maxHP;

        int turn = 0;
        while (true)
        {
            turn++;

            int myPower = attack + weapon;
            if (turn == 1)
                myPower *= (!hasAccessory["CO"] ? 1 : (hasAccessory["DX"] ? 3 : 2));

            int myDamage = max(1, myPower - mob.a);
            mob.h -= myDamage;

            if (mob.h <= 0)
            {
                isKilledBoss = mob.isBoss;
                GetEXP(mob.e);
                grid[y][x] = '.';

                if (isKilledBoss)
                    endingComment = "YOU WIN!";

                if (hasAccessory["HR"])
                    curHP = min(curHP + 3, maxHP);
                break;
            }

            bool isFirstBossHasHU = (turn == 1 && mob.isBoss && hasAccessory["HU"]);
            Damaged((isFirstBossHasHU ? 0 : mob.w), isFirstBossHasHU);

            if (curHP <= 0)
            {
                Die(mob.name);
                if (hasAccessory["RE"])
                    Revive();
                break;
            }
        }
    }
    void Print()
    {
        For(n)
        {
            Forj(m)
                Cout(curPoint == Pos{ i, j } && !isDead ? '@' : grid[i][j]);
            Enter;
        }
        Cout "Passed Turns : " << turn  Endl;
        Cout "LV : " << level Endl;
        Cout "HP : " << curHP << '/' << maxHP Endl;
        Cout "ATT : " << attack << '+' << weapon Endl;
        Cout "DEF : " << defence << '+' << armor Endl;
        Cout "EXP : " << curEXP << '/' << maxEXP Endl;
        Cout endingComment Endl;
    }
};
Player player;


int main()
{
    FastIO;

    Cin n >> m;
    grid.resize(n, vector<char>(m));

    int k = 0;
    int l = 0;
    For(n)
    {
        Forj(m)
        {
            Cin grid[i][j];
            if (grid[i][j] == '@')
            {
                player.curPoint = player.spawnPoint = { i,j };
                grid[i][j] = '.';
            }
            if (grid[i][j] == '&' || grid[i][j] == 'M')
                k++;
            if (grid[i][j] == 'B')
                l++;
        }
    }

    string s;
    Cin s;

    For(k)
    {
        int r, c, w, a, h, e;
        string name;
        Cin r >> c >> name >> w >> a >> h >> e;
        r--, c--;

        monster[{r, c}] = { name,w,a,h,h,e,(grid[r][c] == 'M') };
    }

    For(l)
    {
        int r, c;
        char type;
        string effect;
        Cin r >> c >> type >> effect;
        r--, c--;

        accessay[{r, c}] = { type,effect };
    }

    for (char dir : s)
    {
        player.turn++;
        player.Move(dir);

        int y = player.curPoint.y;
        int x = player.curPoint.x;
        if (grid[y][x] == '^')
            player.StepSpikeTrap();
        elif(grid[y][x] == 'B')
            player.GetItem(y, x);
        elif(grid[y][x] == '&' || grid[y][x] == 'M')
            player.FightMonster(y, x);

        if (player.isDead || player.isKilledBoss)
            break;
    }
    player.Print();
}