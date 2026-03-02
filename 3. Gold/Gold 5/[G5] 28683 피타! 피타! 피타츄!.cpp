#include <iostream>
#include <climits>
#include <cmath>
#include <set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

int Pita(long long n)
{
    set<pair<int, int>> hypo;
    for (long long a = 1; a * a <= n; a++)
    {
        if (a * a == n) return -1;

        long long b = sqrt(n - a * a);
        if (a * a + b * b == n)
            hypo.insert({ min(a * a, b * b),max(a * a, b * b) });
    }

    set<pair<int, int>> leg;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0 && (i & 1) == ((n / i) & 1))
            leg.insert({ i, n / i });
    }

    return hypo.size() + leg.size();
}

int main()
{
    FastIO;

    long long n;
    cin >> n;

    int result = Pita(n);
    if (result == INF)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}