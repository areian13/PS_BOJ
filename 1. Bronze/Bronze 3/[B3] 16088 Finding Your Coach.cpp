#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

char GLRE(int l, int r, int n, int m)
{
    int d = abs(n - m);

    if (n == m)
        return 'G';
    if (r < d && d <= l)
        return 'L';
    if (l < d && d <= r)
        return 'R';
    return 'E';
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int l, r, n, m;
        cin >> l >> r >> n >> m;

        char result = GLRE(l, r, n, m);
        cout << result << '\n';
    }
}