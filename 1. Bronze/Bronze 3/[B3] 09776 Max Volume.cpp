#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

#define PI 3.14159265359

int main()
{
    FastIO;

    int n;
    cin >> n;

    double result = 0;
    while (n--)
    {
        char model;
        cin >> model;

        switch (model)
        {
        case 'C':
        {
            double r, h;
            cin >> r >> h;

            result = max(result, (1.0 / 3) * PI * r * r * h);
            break;
        }

        case 'L':
        {
            double r, h;
            cin >> r >> h;

            result = max(result, PI * r * r * h);
            break;
        }
        case 'S':
        {
            double r;
            cin >> r;

            result = max(result, (4.0 / 3) * PI * r * r * r);
            break;
        }
        }
    }
    lf(3);
    cout << result << '\n';
}