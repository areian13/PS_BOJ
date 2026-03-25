#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanPortal(int n, int m, int c, int d, int sr, int sc)
{
    int r = 0;
    while (true)
    {
        c += d;
        if (c >= m || c < 0)
        {
            d *= -1;
            r++, c += d;
        }

        if (r == n - 1 && c == m - 1)
            return true;
        if (r == sr && c == sc)
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n, m, c, d, sr, sc;
    cin >> n >> m >> c >> d >> sr >> sc;
    c--, sr--, sc--;
    d = (d == 0 ? -1 : +1);

    bool result = CanPortal(n, m, c, d, sr, sc);
    cout << (result ? "YES!" : "NO...") << '\n';
}