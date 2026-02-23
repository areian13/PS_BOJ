#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const long double EPS = 1e-13;
bool Is0(long double v) { return abs(v) < EPS; }

long double WeightGapSum(long double d, vector<int>& c, vector<int>& w)
{
    int n = c.size();
    long double result = 0;
    for (int i = 0; i < n; i++)
        result += abs(d * c[i] - w[i]);
    return result;
}

long double OptDensity(vector<int>& c, vector<int>& w)
{
    long double s = 0, e = 1'000'000;
    while (!Is0(e - s))
    {
        long double p = (s * 2 + e) / 3, q = (s + e * 2) / 3;
        if (WeightGapSum(p, c, w) >= WeightGapSum(q, c, w))
            s = p + EPS;
        else
            e = q - EPS;
    }
    return s;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> c(n), w(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> w[i];

    long double result = OptDensity(c, w);
    printf("%.9llf\n", WeightGapSum(result, c, w));
}