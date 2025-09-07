#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s = "";
    while (s.size() < 100'000)
    {
        string t = s;
        reverse(t.begin(), t.end());
        for (char& c : t)
            c = !(c - '0') + '0';
        s = s + '0' + t;
    }

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int k;
        cin >> k;
        k--;

        printf("Case #%d: %c\n", tc, s[k]);
    }
}