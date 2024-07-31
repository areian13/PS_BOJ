#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int t, d, m;
    cin >> t >> d >> m;

    vector<int> f(m + 2);
    f[0] = 0;
    f[m + 1] = d;
    for (int i = 1; i <= m; i++)
        cin >> f[i];

    bool canEatAll = false;
    for (int i = 0; i <= m; i++)
        canEatAll |= (f[i + 1] - f[i] >= t);

    char result = (canEatAll ? 'Y' : 'N');
    cout << result << '\n';
}