#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;
    
    for (int tc = 1; tc <= TC; tc++)
    {
        array<int, 5> s;
        for (int i = 0; i < 5; i++)
            cin >> s[i];
        sort(s.begin(), s.end());

        if (s[3] - s[1] >= 4)
            cout << "KIN" << '\n';
        else
            cout << s[1] + s[2] + s[3] << '\n';
    }
}