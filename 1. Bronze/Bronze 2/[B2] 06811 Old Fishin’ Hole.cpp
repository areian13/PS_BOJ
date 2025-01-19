#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int b, n, y, l;
    cin >> b >> n >> y >> l;

    int result = 0;
    for (int i = 0; i <= l / b; i++)
    {
        for (int j = 0; j <= l / n; j++)
        {
            for (int k = 0; k <= l / y; k++)
            {
                if (i == 0 && j == 0 && k == 0)
                    continue;
                if (i * b + j * n + k * y <= l)
                {
                    printf("%d Brown Trout, %d Northern Pike, %d Yellow Pickerel\n",
                        i, j, k);
                    result++;
                }
            }
        }
    }

    printf("Number of ways to catch fish: %d\n", result);
}