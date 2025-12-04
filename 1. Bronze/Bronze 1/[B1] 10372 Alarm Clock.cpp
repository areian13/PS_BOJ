#include <iostream>
#include <cstdio>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 10> cnt = { 6,2,5,5,4,5,6,3,7,6 };

    int n;
    cin >> n;

    int result = -1;
    for (int i = 0; i < 1'440; i++)
    {
        int h = i / 60, m = i % 60;
        int sum = cnt[h / 10] + cnt[h % 10] + cnt[m / 10] + cnt[m % 10];

        if (sum == n)
        {
            result = i;
            break;
        }
    }

    if (result == -1)
        printf("Impossible\n");
    else
        printf("%02d:%02d\n", result / 60, result % 60);
}