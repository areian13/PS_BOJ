#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int t = 0;
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;
        
        bool canBuy = false;
        printf("Case %d:\n%d pencils for %d cents\n", ++t, n, n);
        
        vector<array<int, 3>> result;
        for (int j = 1; j * 0.5 <= n; j++)
        {
            for (int k = 1; j * 0.5 + k * 0.25 <= n; k++)
            {
                int i = j / 6.0 + k / 4.0;
                if (i + j + k == n && i * 4 + j * 0.5 + k * 0.25 == n)
                    result.push_back({ i,j,k });
            }
        }
        reverse(result.begin(), result.end());

        if (result.empty())
            printf("No solution found.\n\n");
        else
        {
            for (array<int, 3>& value : result)
            {
                printf("%d at four cents each\n", value[0]);
                printf("%d at two for a penny\n", value[1]);
                printf("%d at four for a penny\n\n", value[2]);
            }
        }
    }
}