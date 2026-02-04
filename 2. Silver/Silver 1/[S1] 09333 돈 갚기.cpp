#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        double ir, ib, im;
        cin >> ir >> ib >> im;

        long long r = ir * 100 + 0.5, b = ib * 100 + 0.5, m = im * 100 + 0.5;
        for (int i = 0; i < 1'200; i++)
        {
            long long p = b * r / 10'000 + (b * r % 10'000 >= 5'000);

            if (p >= m)
                break;

            b += p - m;
            if (b <= 0)
            {
                cout << i + 1 << '\n';
                break;
            }
        }

        if (b > 0)
            cout << "impossible" << '\n';
    }
}