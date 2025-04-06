#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsMo(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    cin.ignore();
    for (int tc = 1; tc <= TC; tc++)
    {
        string s;
        getline(cin, s);

        array<int, 2> result = { 0,0 };
        for (char c : s)
        {
            c |= 32;
            if ('a' <= c && c <= 'z')
                result[IsMo(c)]++;
        }
        cout << result[0] << ' ' << result[1] << '\n';
    }
}