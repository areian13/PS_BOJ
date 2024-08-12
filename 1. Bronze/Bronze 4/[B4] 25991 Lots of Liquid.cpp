#include <iostream>
#include <cstdio>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        double num;
        cin >> num;
        sum += pow(num, 3);
    }
    double result = pow(sum, 1.0 / 3);
    printf("%.6lf", result);
}