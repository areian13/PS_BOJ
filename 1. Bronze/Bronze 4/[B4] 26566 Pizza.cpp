#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define PI 3.14159265359

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int a, p1, r, p2;
        cin >> a >> p1 >> r >> p2;

        double pi1 = (double)a / p1;
        double pi2 = PI * r * r / p2;

        string result = (pi1 < pi2) ? "Whole pizza" : "Slice of pizza";
        cout << result << '\n';
    }
}