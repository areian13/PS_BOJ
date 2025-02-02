#include <iostream>
#include <cstdio>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        pair<int, int> result = { 1e+9,1e+9 };
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i != 0)
                continue;
            
            if (result.first + result.second > i + n / i)
                result = { i, n / i };
        }

        printf("Minimum perimeter is %d with dimensions %d x %d\n",
            (result.first + result.second) * 2, result.first, result.second);
    }
}