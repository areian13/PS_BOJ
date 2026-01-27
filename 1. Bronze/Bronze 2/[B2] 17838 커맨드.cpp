#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool Command(string& s)
{
    if (s.size() != 7) return false;
    for (int i : {1, 4})
    {
        if (s[i] != s[0])
            return false;
    }
    for (int i : {3, 5, 6})
    {
        if (s[i] != s[2])
            return false;
    }
    return s[0] != s[2];
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        string s;
        cin >> s;

        bool result = Command(s);
        cout << result << '\n';
    }
}