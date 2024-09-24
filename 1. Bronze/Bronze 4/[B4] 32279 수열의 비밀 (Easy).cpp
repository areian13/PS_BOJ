#include <iostream>
#include <vector>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, p, q, r, s, a1;
    cin >> n >> p >> q >> r >> s >> a1;

    vector<int> a(n + 1, 0);
    a[1] = a1;
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
            a[i] = p * a[i / 2] + q;
        else
            a[i] = r * a[i / 2] + s;
    }

    int result = accumulate(a.begin() + 1, a.end(), 0);
    cout << result << '\n';
}