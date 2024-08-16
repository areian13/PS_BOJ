#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

array<int, 2> CountYowel(string& s)
{
    array<int, 2> result = { 0,0 };
    for (char c : s)
    {
        result[0] += IsVowel(c);
        result[1] += IsVowel(c) || c == 'y';
    }
    return result;
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    array<int, 2> result = CountYowel(s);
    cout << result[0] << ' ' << result[1] << '\n';
}