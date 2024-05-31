#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

double EIT(int m1, int y1, int m2, int y2)
{
    if (y1 == y2)
        return 0.5 * (m2 - m1) / (12.0 - m1 + 1);
    return 0.5 + (y2 - y1 - 1) + (m2 - 1) / 12.0;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    lf(4);
    while (tc--)
    {
        int m1, y1, m2, y2;
        cin >> m1 >> y1 >> m2 >> y2;

        double result = EIT(m1, y1, m2, y2);
        cout << result << '\n';
    }
}