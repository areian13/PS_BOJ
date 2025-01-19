#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c, d, s;
    cin >> a >> b >> c >> d >> s;

    int ni = 0, by = 0;
    int nc = 0, bc = 0;
    bool nt = true, bt = true;
    for (int i = 0; i < s; i++)
    {
        ni += (nt ? +1 : -1);
        by += (bt ? +1 : -1);
        nc++, bc++;

        if (nt && nc == a)
        {
            nt = false;
            nc = 0;
        }
        else if (!nt && nc == b)
        {
            nt = true;
            nc = 0;
        }

        if (bt && bc == c)
        {
            bt = false;
            bc = 0;
        }
        else if (!bt && bc == d)
        {
            bt = true;
            bc = 0;
        }
    }

    if (ni > by)
        cout << "Nikky" << '\n';
    else if (ni < by)
        cout << "Byron" << '\n';
    else
        cout << "Tied" << '\n';
}