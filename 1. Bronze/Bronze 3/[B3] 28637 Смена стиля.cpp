#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string CamelToSnake(string& s)
{
    int n = s.size();

    string result = "";
    for (int i = 0; i < n; i++)
    {
        if ('A' <= s[i] && s[i] <= 'Z')
        {
            if (i != 0)
                result += '_';
            result += s[i] + 32;
        }
        else
            result += s[i];
    }
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string s;
        cin >> s;

        string result = CamelToSnake(s);
        cout << result << '\n';
    }
}