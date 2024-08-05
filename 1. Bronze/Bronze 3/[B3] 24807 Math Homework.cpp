#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int b, d, c, l;
    cin >> b >> d >> c >> l;

    bool can = false;
    for (int i = 0; i <= l / b; i++)
    {
        for (int j = 0; j <= l / d; j++)
        {
            for (int k = 0; k <= l / c; k++)
            {
                if (b * i + d * j + c * k == l)
                {
                    cout << i << ' ' << j << ' ' << k << '\n';
                    can = true;
                }
            }
        }
    }
    if (!can)
        cout << "impossible" << '\n';
}
