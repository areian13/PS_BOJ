#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountDivisor(int n)
{
    int result = 1;
    for (int i = 1; i <= n / 2; i++)
        result += (n % i == 0);
    return result;
}

int main()
{
    FastIO;

    while (true)
    {
        int m, n;
        cin >> m >> n;

        if (m == 0 && n == 0)
            break;

        int x = 0;
        int y = 0;
        for (int i = m; i <= n; i++)
        {
            int cnt = CountDivisor(i);
            if (cnt >= y)
            {
                y = cnt;
                x = i;
            }
        }
        cout << x << ' ' << y << '\n';
    }
}