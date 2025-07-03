#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string s, c, e;
        getline(cin, s);

        if (s == "ENDOFINPUT")
            break;

        getline(cin, c);
        getline(cin, e);

        for (char i : c)
        {
            if ('A' <= i && i <= 'Z')
                i = (i - 5 - 'A' + 26) % 26 + 'A';
            cout << i;
        }
        cout << '\n';
    }
}