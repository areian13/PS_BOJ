#include <iostream>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int d, o, f;
        cin >> d >> o >> f;

        int result = (d - 1) / o + (d - 1) / f - (d - 1) / lcm(o, f);
        cout << d << ' ' << o << ' ' << f << '\n';
        cout << result << '\n';
    }
}