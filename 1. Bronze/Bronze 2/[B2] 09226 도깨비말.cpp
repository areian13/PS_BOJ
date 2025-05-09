#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string PigLatin(string& s)
{
    int n = s.size();
    int i = 0;
    while (i < n && !IsVowel(s[i]))
        i++;
    return s.substr(i) + s.substr(0, i) + "ay";
}

int main()
{
    FastIO;

    while (true)
    {
        string s;
        cin >> s;

        if (s == "#")
            break;

        string result = PigLatin(s);
        cout << result << '\n';
    }
}