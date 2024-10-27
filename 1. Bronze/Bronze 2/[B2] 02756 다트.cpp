#include <iostream>
#include <cstdio>
#include <array>
#include <cmath>
#include <algorithm>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        array<int, 2> scores = { 0,0 };
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                double x, y;
                cin >> x >> y;

                double dist = sqrt(x * x + y * y);
                bool isBoundary = ((double)(int)dist == dist) && ((int)dist % 3 == 0);
                scores[i] += min(max(100 - ((int)dist / 3 - isBoundary) * 20, 0), 100);
            }
        }

        string result = (scores[0] == scores[1] ? "TIE" : (scores[0] > scores[1] ? "PLAYER 1 WINS" : "PLAYER 2 WINS"));
        printf("SCORE: %d to %d, %s.\n", scores[0], scores[1], result.c_str());
    }
}