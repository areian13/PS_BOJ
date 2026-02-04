#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

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
        for (int i = 0; i < 4; i++)
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
        else if (item.type == 'A')
            armor = stoi(item.effect);
        else if (item.type == 'O')
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
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << (curPoint == Pos{ i, j } && !isDead ? '@' : grid[i][j]);
            cout << '\n';
        }
        cout << "Passed Turns : " << turn << '\n';
        cout << "LV : " << level << '\n';
        cout << "HP : " << curHP << '/' << maxHP << '\n';
        cout << "ATT : " << attack << '+' << weapon << '\n';
        cout << "DEF : " << defence << '+' << armor << '\n';
        cout << "EXP : " << curEXP << '/' << maxEXP << '\n';
        cout << endingComment << '\n';
    }
};
Player player;


int main()
{
    FastIO;

    cin >> n >> m;
    grid.resize(n, vector<char>(m));

    int k = 0;
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
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
    cin >> s;

    for (int i = 0; i < k; i++)
    {
        int r, c, w, a, h, e;
        string name;
        cin >> r >> c >> name >> w >> a >> h >> e;
        r--, c--;

        monster[{r, c}] = { name,w,a,h,h,e,(grid[r][c] == 'M') };
    }

    for (int i = 0; i < l; i++)
    {
        int r, c;
        char type;
        string effect;
        cin >> r >> c >> type >> effect;
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
        else if (grid[y][x] == 'B')
            player.GetItem(y, x);
        else if (grid[y][x] == '&' || grid[y][x] == 'M')
            player.FightMonster(y, x);

        if (player.isDead || player.isKilledBoss)
            break;
    }
    player.Print();
}