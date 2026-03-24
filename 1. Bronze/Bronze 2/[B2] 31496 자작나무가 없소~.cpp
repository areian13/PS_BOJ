#include <iostream>
#include <string>
#include <sstream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int IsIn(string a, string& s)
{
    for (char& c : a)
    {
        if (c == '_')
            c = ' ';
    }

    stringstream ss(a);
    string word;

    while (ss >> word)
    {
        if (word == s)
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        string a;
        int c;
        cin >> a >> c;

        result += IsIn(a, s) * c;
    }
    cout << result << '\n';
}