#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long Dist(long long d, vector<long long>& x)
{
    int n = x.size();
    long long result = 0;
    for (int i = 0; i < n; i++)
        result += abs(d * i - x[i]);
    return result;
}

long long TS(vector<long long>& x)
{
    int n = x.size();

    long long s = 0, e = x[n - 1];
    while (e - s >= 3)
    {
        long long p = (s * 2 + e) / 3, q = (s + e * 2) / 3;
        if (Dist(p, x) >= Dist(q, x))
            s = p;
        else
            e = q;
    }

    long long result = LLONG_MAX;
    for (int i = s; i <= e; i++)
        result = min(result, Dist(i, x));
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<long long> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    long long result = TS(x);
    cout << result << '\n';
}