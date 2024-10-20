#include <iostream>
#include <array>
#include <cfloat>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<double, 5> pasteCoef = { 0.5,0.5,0.25,0.0625,0.5625 };
array<double, 4> toppingCoef = { 1,30,25,10 };

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        double pan = DBL_MAX;
        for (int i = 0; i < 5; i++)
        {
            int paste;
            cin >> paste;

            pan = min(pan, paste / pasteCoef[i]);
        }

        int cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            int topping;
            cin >> topping;

            cnt += topping / toppingCoef[i];
        }

        int result = min((int)pan, cnt);
        cout << result << '\n';
    }
}