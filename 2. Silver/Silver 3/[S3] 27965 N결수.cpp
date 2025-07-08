#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int GetPow10(int n)
{
    int result = 1;
    while (n >= 10)
    {
        result *= 10;
        n /= 10;
    }
    return result;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    long long result = 0;
    for (int i = 1; i <= n; i++)
        result = (result * GetPow10(i * 10) + i) % k;
    cout << result << '\n';
}