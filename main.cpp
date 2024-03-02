#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Print(string& s)
{
    int n = s.size();

    if (n <= 2 || s[0] != '"' || s[n - 1] != '"')
        return "CE";

    return s.substr(1, n - 2);
}

int main()
{
    FastIO;

    string s;
    getline(cin, s);

    string result = Print(s);
    cout << result << '\n';
}