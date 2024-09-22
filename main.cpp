#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    for (int i = INT_MIN; i <= INT_MAX; i++)
    {
        if (i == -i)
            cout << i << '\n';
    }
}