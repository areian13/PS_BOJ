#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

double f(double x, vector<double>& c)
{
    int k = c.size();

    double result = 0;
    double b = 1;
    for (int i = k - 1; i >= 0; i--)
    {
        result += c[i] * b;
        b *= x;
    }
    return result;
}

vector<double> Integration(vector<double>& c)
{
    int k = c.size();

    vector<double> result(k + 1, 0);
    for (int i = 0; i < k; i++)
        result[i] = c[i] / (k - i);
    return result;
}

double Quadrature(double a, double dx, double eps, int n, vector<double>& c)
{
    double result = 0;
    for (int k = 0; k < n; k++)
        result += f(a + k * dx + eps, c);
    result *= dx;
    return result;
}

double GetEpsilon(vector<double>& c, double a, double b, int n)
{
    vector<double> integral = Integration(c);
    double lValue = f(b, integral) - f(a, integral);
    double dx = (b - a) / n;
    
    double start = 0, end = dx;
    double result = 0;

    while (abs(end - start) >= 1e-20)
    {
        double mid = (start + end) / 2;
        double rValue = Quadrature(a, dx, mid, n, c);

        if (abs(lValue - rValue) < 1e-4)
            return mid;

        if (lValue > rValue)
            start = mid;
        else
            end = mid;
    }
    return -1;
}

int main()
{
    FastIO;

    int k;
    cin >> k;

    vector<double> c(k + 1);
    for (int i = 0; i < k + 1; i++)
        cin >> c[i];

    int a, b, n;
    cin >> a >> b >> n;

    double result = GetEpsilon(c, a, b, n);
    printf("%.5lf\n", result);
}