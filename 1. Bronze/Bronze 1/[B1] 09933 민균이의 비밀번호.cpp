#include <iostream>
#include <set>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    set<string> has;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        has.insert(s);

        reverse(s.begin(), s.end());
        if (has.count(s) == 1)
            cout << s.size() << ' ' << s[s.size() / 2] << '\n';
    }
}