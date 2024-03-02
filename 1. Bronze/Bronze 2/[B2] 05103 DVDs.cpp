#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string dvd;
        cin >> dvd;

        if (dvd == "#")
            break;

        int m, s, t;
        cin >> m >> s >> t;

        while (t--)
        {
            char sr;
            int n;
            cin >> sr >> n;

            s = max(min(s + n * (sr == 'S' ? -1 : +1), m), 0);
        }
        cout << dvd << ' ' << s << '\n';
    }
}