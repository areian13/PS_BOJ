#include <iostream>
#include <cstdio>

using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    printf("Sun Mon Tue Wed Thr Fri Sat\n");
    for (int i = 0; i < n - 1; i++)
        printf("    ");
    for (int i = 1; i <= k; i++)
    {
        printf("%3d", i);
        printf((i + n - 1) % 7 == 0 ? "\n" : " ");
    }
}