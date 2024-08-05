#include <iostream>
#include <cstdio>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<bool, 12 * 31 + 1> isBirth = { false, };

    int n;
    scanf("%d", &n);

    while (n--)
    {
        int m, d;
        scanf("%d/%d", &m, &d);

        isBirth[(m - 1) * 31 + d] = true;
    }

    int result = 0;
    for (int i = 1; i <= 12 * 31; i++)
        result += isBirth[i];
    cout << result << '\n';
}