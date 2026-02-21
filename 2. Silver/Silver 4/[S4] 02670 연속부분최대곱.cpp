#include <iostream>
#include <cstdio>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<double> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    double result = 0;
    for (int i = 0; i < n - 1; i++)
    {
        double value = 1;
        for (int j = i; j < n; j++)
        {
            value *= v[j];
            result = max(result, value);
        }
    }

    printf("%.3lf\n", result);
}