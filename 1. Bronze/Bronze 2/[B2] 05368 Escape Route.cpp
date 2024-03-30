#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

double Dist(Pos a, Pos b)
{
    return sqrt(pow(a.y - b.y, 2) + pow(a.x - b.x, 2));
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        vector<string> space(n);
        Pos start;
        for (int i = 0; i < n; i++)
        {
            cin >> space[i];
            for (int j = 0; j < n; j++)
            {
                if (space[i][j] == 's')
                    start = { i,j };
            }
        }

        double minDist = INT_MAX;
        Pos end;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (space[i][j] != 'p')
                    continue;

                double dist = Dist(start, { i,j });
                if (dist < minDist)
                {
                    minDist = dist;
                    end = { i,j };
                }
            }
        }
        printf("(%d,%d):(%d,%d):%.2lf\n", start.y, start.x, end.y, end.x, minDist);
    }
}