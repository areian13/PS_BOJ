#include <iostream>
#include <vector>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<double> money(n);
    for (int i = 0; i < n; i++)
        cin >> money[i];

    int l, c;
    cin >> l >> c;

    for (int i = 0; i < c; i++)
    {
        double sum = accumulate(money.begin(), money.end(), 0.0);
        for (int j = 0; j < n; j++)
            money[j] += l * money[j] / sum;
    }

    lf(9);
    cout << money[0] << '\n';
}