#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        string s;
        cin >> s;

        int mx, MX, my, MY;
        mx = MX = my = MY = 0;
        for (char c : s)
        {
            if (c == 'U')
                my++, MY++;
            else if (c == 'R')
                mx++, MX++;
            else if (c == 'D')
                my--, MY--;
            else if (c == 'L')
                mx--, MX--;
            else
                mx--, MX++, my--, MY++;
        }

        cout << mx << ' ' << my << ' ' << MX << ' ' << MY << '\n';
    }
}