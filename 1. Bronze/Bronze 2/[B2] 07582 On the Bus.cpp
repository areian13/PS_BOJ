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
        string b;
        int z;
        cin >> b >> z;

        if (b == "#" && z == 0)
            break;

        int p, s;
        cin >> p >> s;

        for (int i = 0; i < s; i++)
        {
            int d, u;
            cin >> d >> u;

            p = min(p - d + u, z);
        }
        cout << b << ' ' << p << '\n';
    }
}