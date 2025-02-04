#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsMo(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

string Canadian(string& s)
{
    int n = s.size();
    if (n >= 4 && !IsMo(s[n - 3]) && s.substr(n-2)=="or")
        return s.substr(0, n - 2) + "our";
    return s;
}

int main()
{
    FastIO;

    while (true)
    {
        string s;
        cin >> s;

        if (s == "quit!")
            break;

        string result = Canadian(s);
        cout << result << '\n';
    }
}