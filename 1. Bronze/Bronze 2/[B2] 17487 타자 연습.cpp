#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

pair<int, int> Typing(string& s)
{
    static const string right = "uiophjklnm";

    pair<int, int> result = { 0,0 };
    int sc = 0;
    for (char c : s)
    {
        if (c == ' ')
        {
            sc++;
            continue;
        }

        if ('A' <= c && c <= 'Z')
        {
            sc++;
            c += 32;
        }

        (right.find(c) == -1 ? result.first : result.second)++;
    }

    while (sc > 0)
    {
        (result.first <= result.second ? result.first : result.second)++;
        sc--;
    }
    return result;
}

int main()
{
    FastIO;

    string s;
    getline(cin, s);

    auto [l, r] = Typing(s);
    cout << l << ' ' << r << '\n';
}