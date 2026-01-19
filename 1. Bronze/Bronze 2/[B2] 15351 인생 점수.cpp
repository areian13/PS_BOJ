#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    cin.ignore();
    for (int tc = 1; tc <= TC; tc++)
    {
        string s;
        getline(cin, s);

        int result = 0;
        for (char c : s)
        {
            if (c == ' ') continue;
            result += c - 'A' + 1;
        }

        if (result == 100)
            cout << "PERFECT LIFE" << '\n';
        else
            cout << result << '\n';
    }
}