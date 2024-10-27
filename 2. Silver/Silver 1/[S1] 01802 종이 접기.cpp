#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsSame(int s, int e, string& p)
{
    int m = (s + e) / 2;
    int l = (e - s) / 2;
    for (int i = 0; i < l; i++)
    {
        if (p[s + i] == p[e - i])
            return false;
    }
    return true;
}

bool IsFolded(int s, int e, string& p)
{
    if (s == e)
        return true;
    if (!IsSame(s, e, p))
        return false;

    int m = (s + e) / 2;
    return IsFolded(s, m - 1, p);
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string s;
        cin >> s;

        string result = IsFolded(0, s.size() - 1, s) ? "YES" : "NO";
        cout << result << '\n';
    }
}