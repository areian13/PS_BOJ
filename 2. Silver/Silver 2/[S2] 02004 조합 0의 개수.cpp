#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long CountK(int n, int k)
{
    long long result = 0;
    for (long long i = k; i <= n; i *= k)
        result += n / i;
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    long long c5 = CountK(n, 5) - CountK(m, 5) - CountK(n - m, 5);
    long long c2 = CountK(n, 2) - CountK(m, 2) - CountK(n - m, 2);
    long long result = min(c5, c2);
    cout << result << '\n';
}