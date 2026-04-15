#include <iostream>
#include <string>
#include <set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void DeleteAt(const string& s, set<string>& decodes)
{
    int n = s.size();
    if (s[0] == '.' || s[n - 1] == '.')
        return;
    for (int i = 1; i < n - 2; i++)
    {
        if (s.substr(i, 2) == "at" && s[i - 1] != '.' && s[i + 2] != '.')
            decodes.insert(s.substr(0, i) + '@' + s.substr(i + 2));
    }
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    int n = s.size();
    set<string> decodes;
    DeleteAt(s, decodes);
    for (int i = 0; i < n; i++)
    {
        if (s.substr(i, 6) == "nospam")
            DeleteAt(s.substr(0, i) + s.substr(i + 6), decodes);
    }

    for (const string& decode : decodes)
        cout << decode << '\n';
}