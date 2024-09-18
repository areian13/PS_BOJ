#include <iostream>
#include <cstdio>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int sum = 0;
    int maxScore = 0;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;

        sum += s;
        maxScore = max(maxScore, s);
    }

    double result = sum * 100.0 / maxScore / n;
    printf("%.2lf\n", result);
}