#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc = 0;
    while (true)
    {
        char a, b;
        cin >> a >> b;

        if (a == '#' && b == '#')
            break;

        int n;
        cin >> n;

        cout << "Case" << ' ' << ++tc << '\n';
        cin.ignore();
        for (int i = 0; i < n; i++)
        {
            string s;
            getline(cin, s);

            for (char c : s)
            {
                char t = c | 32;
                cout << (t == a || t == b ? '_' : c);
            }
            cout << '\n';
        }
        cout << '\n';
    }
}