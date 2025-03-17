#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string s;
        int n;
        cin >> s >> n;

        if (s == "#" && n == 0)
            break;

        while (true)
        {
            char t;
            int k;
            cin >> t >> k;

            if (t == 'X' && k == 0)
                break;

            if (t == 'B')
            {
                if (n + k > 68)
                    continue;
                else
                    n += k;
            }
            else
            {
                if (n < k)
                    continue;
                n -= k;
            }
        }
        cout << s << ' ' << n << '\n';
    }
}