#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    getline(cin, s);

    array<int, 26> cnt = { 0, };
    for (char c : s)
    {
        c |= 32;
        if ('a' <= c && c <= 'z')
            cnt[c - 'a']++;
    }

    for (int i = 0; i < 26; i++)
        cout << (char)(i + 'A') << " | " << string(cnt[i], '*') << '\n';
}