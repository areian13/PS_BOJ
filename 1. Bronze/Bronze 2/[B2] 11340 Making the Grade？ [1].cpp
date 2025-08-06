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
        int a, b, c;
        cin >> a >> b >> c;

        int result = 101;
        while (true)
        {
            double value = a * 0.15 + b * 0.20 + c * 0.25 + (result - 1) * 0.40;
            if (value < 90)
                break;
            result--;
        }

        if (result == 101)
            cout << "impossible" << '\n';
        else
            cout << result << '\n';
    }
}