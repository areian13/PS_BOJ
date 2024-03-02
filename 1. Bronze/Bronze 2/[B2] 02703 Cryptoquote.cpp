#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Disp(string& str, string& rule)
{
    string result = "";
    for (char c : str)
        result += (('A' <= c && c <= 'Z') ? rule[c - 'A'] : c);
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        cin.ignore();

        string str, rule;
        getline(cin, str) >> rule;

        string result = Disp(str, rule);
        cout << result << '\n';
    }
}