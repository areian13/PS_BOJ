#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int x, y;
    friend istream& operator>>(istream& is, Pos& p)
    {
        is >> p.x >> p.y;
        return is;
    }
};
struct Info
{
    int nth, cnt;
};

double Dist(Pos& a, Pos& b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
    FastIO;

    int n, r;
    double d;
    Pos enemy;
    cin >> n >> r >> d >> enemy;

    vector<Pos> tower(n + 1);
    tower[0] = enemy;
    for (int i = 1; i <= n; i++)
        cin >> tower[i];

    vector<vector<int>> edge(n + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (Dist(tower[i], tower[j]) > r)
                continue;

            edge[i].push_back(j);
            edge[j].push_back(i);
        }
    }

    vector<bool> isVisited(n + 1, false);
    isVisited[0] = true;

    queue<Info> Q;
    Q.push({ 0,0 });

    double result = 0;
    while (!Q.empty())
    {
        int cur = Q.front().nth;
        int cnt = Q.front().cnt;
        Q.pop();

        for (int nxt : edge[cur])
        {
            if (isVisited[nxt])
                continue;

            isVisited[nxt] = true;
            result += d / (1LL << cnt);
            Q.push({ nxt,cnt + 1 });
        }
    }

    printf("%.2lf\n", result);
}