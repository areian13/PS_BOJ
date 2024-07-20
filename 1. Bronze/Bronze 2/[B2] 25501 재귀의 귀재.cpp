#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void Recursrucer(int l, int r, string& s, array<int, 2>& result)
{
    result[1]++;
    if (l >= r)
    {
        result[0] = true;
        return;
    }
    if (s[l] != s[r])
        return;
    return Recursrucer(l + 1, r - 1, s, result);
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

        array<int, 2> result = { 0,0 };
        Recursrucer(0, s.size() - 1, s, result);
        cout << result[0] << ' ' << result[1] << '\n';
    }
}