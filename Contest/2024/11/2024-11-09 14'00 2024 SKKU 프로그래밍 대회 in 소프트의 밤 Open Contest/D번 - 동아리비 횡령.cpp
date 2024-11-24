#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsNum(string n)
{
    for (char c : n)
    {
        if (!('0' <= c && c <= '9'))
            return false;
    }
    return true;
}

bool IsCute(string& s)
{
    int n = s.size();

    if (n == 1 || n % 2 == 0 || s[n / 2] != '+')
        return false;

    string s1 = s.substr(0, n / 2);
    string s2 = s.substr(n / 2 + 1);

    if (!IsNum(s1) || !IsNum(s2))
        return false;
    return (s1[0] != '0' && s1 == s2);
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    string result = IsCute(s) ? "CUTE" : "No Money";
    cout << result << '\n';
}