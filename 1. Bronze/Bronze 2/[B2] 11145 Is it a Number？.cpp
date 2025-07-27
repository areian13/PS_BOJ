#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsNum(string& s)
{
    for (char c : s)
    {
        if (!('0' <= c && c <= '9'))
            return false;
    }
    return true;
}

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

        while (s.size() > 1 && s.back() == ' ')
            s.pop_back();
        reverse(s.begin(), s.end());
        while (s.size() > 1 && (s.back() == '0' || s.back() == ' '))
            s.pop_back();
        reverse(s.begin(), s.end());

        bool result = IsNum(s);
        if (result)
            cout << s << '\n';
        else
            cout << "invalid input" << '\n';
    }
}