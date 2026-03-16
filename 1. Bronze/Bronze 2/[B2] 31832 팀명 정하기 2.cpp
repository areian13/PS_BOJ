#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsTeam(string& s)
{
    if (s.size() > 10) return false;

    array<int, 2> cnt = { 0,0 };
    bool hasChar = false;
    for (char c : s)
    {
        if (!('0' <= c && c <= '9'))
            hasChar = true;
        if ('A' <= c && c <= 'Z')
            cnt[0]++;
        if ('a' <= c && c <= 'z')
            cnt[1]++;
    }
    return hasChar && cnt[0] <= cnt[1];
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (IsTeam(s))
            cout << s << '\n';
    }
}