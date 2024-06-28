#include <iostream>
#include <string>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define ¥Õ 1.61803399

bool IsGoldenRatio(double r)
{
    return fabs(¥Õ - r) / ¥Õ * 100 <= 1;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        double a, b;
        cin >> a >> b;

        string result = IsGoldenRatio(a / b) ? "golden" : "not";
        cout << result << '\n';
    }
}