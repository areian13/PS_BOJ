#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int m, n;
    cin >> m >> n;

    int result = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            result += (i + j == 10);
    }

    char format[100];
    sprintf(format, "There %s to get the sum 10.", (result != 1 ? "are %d ways" : "is %d way"));
    printf(format, result);
}