#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool IsMoreVowel(string& name)
{
    int cnt = 0;
    for (char c : name)
        cnt += (IsVowel(c) ? +1 : -1);
    return (cnt > 0);
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string name;
        cin >> name;

        cout << name << '\n';

        bool result = IsMoreVowel(name);
        cout << result << '\n';
    }
}