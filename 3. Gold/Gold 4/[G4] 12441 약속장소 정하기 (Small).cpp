#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Human
{
    int x, v;
};

void FW(vector<vector<long long>>& dist)
{
    int n = dist.size();

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    dist[i][i] = 0;
                    continue;
                }
                if (dist[i][k] == LLONG_MAX || dist[k][j] == LLONG_MAX)
                    continue;

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int FastestTime(vector<Human>& humans, vector<vector<long long>>& dist)
{
    int n = dist.size();
    
    FW(dist);

    long long result = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        long long time = 0;
        for (Human& human : humans)
        {
            if (dist[human.x][i] == LLONG_MAX)
            {
                time = LLONG_MAX;
                break;
            }

            time = max(time, dist[human.x][i] * human.v);
        }
        result = min(result, time);
    }

    if (result == LLONG_MAX)
        return -1;
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int n, p, m;
        cin >> n >> p >> m;

        vector<Human> humans(p);
        for (int i = 0; i < p; i++)
        {
            int x, v;
            cin >> x >> v;
            x--;

            humans[i] = { x,v };
        }

        vector<vector<long long>> dist(n, vector<long long>(n, LLONG_MAX));
        for (int i = 0; i < m; i++)
        {
            int d, l, c;
            cin >> d >> l >> c;
            c--;

            for (int j = 0; j < l - 1; j++)
            {
                int k;
                cin >> k;
                k--;

                dist[c][k] = d;
                dist[k][c] = d;
                c = k;
            }
        }

        int result = FastestTime(humans, dist);
        printf("Case #%d: %d\n", t, result);
    }
}