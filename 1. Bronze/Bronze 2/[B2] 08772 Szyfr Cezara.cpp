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
        int n;
        string s;
        char c;
        cin >> n >> s >> c;

        int d = (c - s[0] + 26) % 26;
        for (char c : s)
        {
            c = (c - 'a' + d + 26) % 26 + 'a';
            cout << c;
        }
        cout << '\n';
    }
}