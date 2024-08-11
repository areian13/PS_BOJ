#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsPalindrome(string& s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}

string Splitology(string& s)
{
    int n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        string a = s.substr(0, i + 1);
        string b = s.substr(i + 1, n - i);
        if (IsPalindrome(a) && IsPalindrome(b))
            return a + ' ' + b;
    }
    return "NO";
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    string result = Splitology(s);
    cout << result << '\n';
}