#include <iostream>
#include <cstdio>

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

        int result = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int v;
                cin >> v;

                if (j == 0 || j == i - 1 || i == n)
                    result += v;
            }
        }
        printf("Case #%d:%d\n", ++tc, result);
    }
}