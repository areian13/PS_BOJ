#include <iostream>
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc = 0;
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<int> bricks(n);
        for (int i = 0; i < n; i++)
            cin >> bricks[i];
        int avg = accumulate(bricks.begin(), bricks.end(), 0) / n;

        int result = 0;
        for (int i = 0; i < n; i++)
            result += max(bricks[i] - avg, 0);

        printf("Set #%d\n", ++tc);
        printf("The minimum number of moves is %d.\n", result);
        printf("\n");
    }
}