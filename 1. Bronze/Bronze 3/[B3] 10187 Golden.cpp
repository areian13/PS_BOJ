#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define �� 1.61803399

bool IsGoldenRatio(double a, double b)
{
    return fabs(�� - (a / b)) / �� * 100 <= 1;
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

        string result = IsGoldenRatio(a, b) ? "golden" : "not";
        cout << result << '\n';
    }
}