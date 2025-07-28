#include <iostream>
#include <string>
#include <sstream>

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

        stringstream ss(s);
        string t;
        while (ss >> t)
        {
            int result = 0;
            for (char c : t)
                result += c - 'a';
            result %= 27;

            if (result == 26)
                cout << ' ';
            else
                cout << (char)(result + 'a');
        }
        cout << '\n';
    }
}