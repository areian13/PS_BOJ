#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int ListGCD(vector<int>& list)
{
    if (list.empty())
        return 1;

    int gcd = list[0];
    for (int e : list)
        gcd = GCD(gcd, e);
    return gcd;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<double> x(n);
    double minX = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        minX = min(minX, x[i]);
    }

    double maxX = 0;
    for (int i = 0; i < n; i++)
    {
        x[i] /= minX;
        maxX = max(maxX, x[i]);
    }

    int d = 0;
    double minDiff = 1;
    for (int tempD = 1; (int)(tempD * maxX + 0.5) <= 10'000; tempD++)
    {
        double diff = 0;
        for (int i = 0; i < n; i++)
            diff = max(diff, abs((int)(tempD * x[i] + 0.5) - tempD * x[i]));

        if (diff < minDiff)
        {
            minDiff = diff;
            d = tempD;
        }
    }

    vector<int> r(n);
    for (int i = 0; i < n; i++)
        r[i] = x[i] * d + 0.5;

    int gcd = ListGCD(r);
    for (int i = 0; i < n; i++)
    {
        r[i] /= gcd;
        cout << r[i] << '\n';
    }
}