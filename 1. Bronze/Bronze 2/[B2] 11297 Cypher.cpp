#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int m, d, y;
        cin >> m >> d >> y;
        cin.ignore();

        if (m == 0 && d == 0 && y == 0)
            break;

        int shift = (m + d + y) % 25 + 1;
        string s;
        getline(cin, s);

        for (char c : s)
        {
            if ('a' <= c && c <= 'z')
                c = (c - 'a' - shift + 26) % 26 + 'a';
            cout << c;
        }
        cout << '\n';
    }
}