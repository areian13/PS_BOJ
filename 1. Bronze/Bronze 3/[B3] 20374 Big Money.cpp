#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    long double result = 0;
    while (true)
    {
        long double e;
        cin >> e;

        if (cin.eof())
            break;

        result += e;
    }

    lf(2);
    cout << result << '\n';
}
