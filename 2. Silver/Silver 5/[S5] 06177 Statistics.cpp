#include <iostream>
#include <vector>
#include <algorithm>
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

    vector<int> set(n);
    for (int i = 0; i < n; i++)
        cin >> set[i];
    sort(set.begin(), set.end());

    double mean = accumulate(set.begin(), set.end(), 0.0) / n;
    double medi = (n % 2 == 1 ? set[n / 2] : (set[n / 2] + set[n / 2 - 1]) / 2.0);

    lf(3);
    cout << mean << '\n';
    cout << medi << '\n';
}