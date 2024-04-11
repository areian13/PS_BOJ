#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long VeryHardProblem(long long n, long long m)
{
    if (n >= m)
        return 0;

    long long result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
        result %= m;
    }

    return result;
}

int main()
{
    FastIO;

    long long n, m;
    cin >> n >> m;

    long long result = VeryHardProblem(n, m);
    cout << result << '\n';
}