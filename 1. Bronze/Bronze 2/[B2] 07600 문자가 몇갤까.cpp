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

        int has = 0;
        for (char c : s)
        {
            c |= 32;
            if ('a' <= c && c <= 'z')
                has |= (1 << (c - 'a'));
        }

        int result = 0;
        for (int i = 0; i < 26; i++)
            result += !!(has & (1 << i));
        cout << result << '\n';
    }
}