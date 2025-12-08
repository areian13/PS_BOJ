#include <iostream>
#include <cstdio>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsMo(char c)
{
    c |= 32;
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
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

        char c = s.back();
        printf("Case #%d: %s is ruled by %s.\n", tc, s.c_str(), (IsMo(c) ? "a queen" : ((c | 32) == 'y' ? "nobody" : "a king")));
    }
}