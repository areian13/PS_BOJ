#include <iostream>
#include <string>
#include <array>
#include <sstream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 3> Ex(string& s, char e)
{
    array<int, 3> result;
    for (char& c : s)
    {
        if (c == e)
            c = ' ';
    }
    stringstream ss(s);
    string temp;
    for (int i = 0; i < 3; i++)
    {
        ss >> temp;
        result[i] = stoi(temp);
    }
    if (e == '/')
        swap(result[0], result[1]);
    return result;
}
array<int, 3> ParseDate(string& s)
{
    if (s.find('.') != string::npos)
        return Ex(s, '.');
    return Ex(s, '/');
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

        auto [d, m, y] = ParseDate(s);
        printf("%02d.%02d.%04d %02d/%02d/%04d\n", d, m, y, m, d, y);
    }
}