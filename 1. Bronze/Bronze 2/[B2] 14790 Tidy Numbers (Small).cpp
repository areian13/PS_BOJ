#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsTidy(long long n)
{
    while (n > 9)
    {
        if (n / 10 % 10 > n % 10)
            return false;
        n /= 10;
    }
    return true;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        long long n;
        cin >> n;

        while (!IsTidy(n))
            n--;

        printf("Case #%d: %d\n", tc, n);
    }
}