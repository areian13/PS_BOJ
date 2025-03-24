#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string s;
        getline(cin, s);

        if (s == "#")
            break;

        array<bool, 26> isUsed = { false, };
        int result = 0;
        for (char c : s)
        {
            c |= 32;
            if ('a' <= c && c <= 'z')
            {
                result += !isUsed[c - 'a'];
                isUsed[c - 'a'] = true;
            }
        }
        cout << result << '\n';
    }
}