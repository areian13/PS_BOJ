#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsAnagram(string& s0, string& s1)
{
    array<int, 26> cnt = { 0, };
    for (char c : s0)
    {
        if ('A' <= c && c <= 'Z')
            cnt[c - 'A']++;
    }

    for (char c : s1)
    {
        if ('A' <= c && c <= 'Z')
        {
            if (cnt[c - 'A'] <= 0)
                return false;
            cnt[c - 'A']--;
        }
    }
    return true;
}

int main()
{
    FastIO;

    string s0, s1;
    getline(cin, s0), getline(cin, s1);

    bool result = IsAnagram(s0, s1);
    if (result == true)
        cout << "Is an anagram." << '\n';
    else
        cout << "Is not an anagram." << '\n';
}