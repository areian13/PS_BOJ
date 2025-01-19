#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int m, p, l, e, r, s, n;
        cin >> m >> p >> l >> e >> r >> s >> n;

        if (cin.eof())
            break;

        for (int i = 0; i < n; i++)
        {
            int temp = l;
            l = m * e;
            m = p / s;
            p = temp / r;
        }

        cout << m << '\n';
    }
}