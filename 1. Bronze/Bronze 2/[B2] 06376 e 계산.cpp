#include <iostream>
#include <cstdio>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");

    array<int, 10> facto;
    facto[0] = 1;
    for (int i = 1; i <= 9; i++)
        facto[i] = facto[i - 1] * i;

    for (int n = 3; n <= 9; n++)
    {
        double e = 0;
        for (int i = 0; i <= n; i++)
            e += 1.0 / facto[i];
        printf("%d %.9lf\n", n, e);
    }
}