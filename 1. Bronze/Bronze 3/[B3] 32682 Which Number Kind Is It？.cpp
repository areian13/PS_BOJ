#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        bool o = (n % 2 == 1);
        bool s = ((int)sqrt(n) == sqrt(n));

        if (!o && !s)
            cout << "EMPTY" << '\n';
        else
        {
            if (o)
                cout << "O";
            if (s)
                cout << "S";
            cout << '\n';
        }
    }
}