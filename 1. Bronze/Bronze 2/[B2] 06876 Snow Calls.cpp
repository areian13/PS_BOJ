#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

char CtoI(char c)
{
    static string numBound = "CFILOSVZ";
    for (int i = 0; numBound[i] != '\0'; i++)
    {
        if (numBound[i] >= c)
            return i + '2';
    }
    return '0';
}

string FormattedNum(string& s)
{
    string result = "";
    for (char c : s)
    {
        if ('0' <= c && c <= '9')
            result += c;
        else if ('A' <= c && c <= 'Z')
            result += CtoI(c);
    }

    result.insert(result.begin() + 3, '-');
    result.insert(result.begin() + 7, '-');
    return result.substr(0, 12);
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

        string result = FormattedNum(s);
        cout << result << '\n';
    }
}