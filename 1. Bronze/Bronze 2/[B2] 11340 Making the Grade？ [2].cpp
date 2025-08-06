#include <iostream>
#include <cmath>

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

        int score = 9000 - (a * 15 + b * 20 + c * 25);
        int result = (score * 25 + 999) / 1000;
        if (result > 100)
            cout << "impossible" << '\n';
        else
            cout << result << '\n';
    }
}