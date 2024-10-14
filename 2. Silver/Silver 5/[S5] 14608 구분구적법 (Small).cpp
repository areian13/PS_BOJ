#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

double GetEps(double a, double b, double n, vector<double>& coef)
{
    int k = coef.size() - 1;

    double lValue = 0;
    for (int i = 0; i < k + 1; i++)
        lValue += coef[i] / (k + 1 - i) * (pow(b, k + 1 - i) - pow(a, k + 1 - i));

    double dx = (b - a) / n;
    double start = 0, end = dx;

    while (abs(start - end) > 1e-5)
    {
        double eps = (start + end) / 2;

        double rValue = 0;
        for (int i = 0; i < k + 1; i++)
        {
            double temp = 0;
            for (int j = 0; j < n; j++)
                temp += pow(a + j * dx + eps, k - i);
            rValue += temp * coef[i] * dx;
        }

        if (abs(lValue - rValue) <= 1e-4)
            return eps;

        if (lValue < rValue)
            end = eps;
        else if (lValue > rValue)
            start = eps;
    }
    return -1;
}

int main()
{
    FastIO;

    int k;
    cin >> k;

    vector<double> coef(k + 1);
    for (int i = 0; i < k + 1; i++)
        cin >> coef[i];

    double a, b, n;
    cin >> a >> b >> n;

    lf(4);
    double result = GetEps(a, b, n, coef);
    cout << result << '\n';
}