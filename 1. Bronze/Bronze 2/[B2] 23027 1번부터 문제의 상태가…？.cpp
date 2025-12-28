#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void Conversion(string& s, char t)
{
    for (char& c : s)
    {
        if (c > t && (c == 'B' || c == 'C' || c == 'D' || c == 'F'))
            c = t;
    }
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    bool flag = false;
    for (char c : "ABC")
    {
        if (s.find(c) != -1)
        {
            Conversion(s, c);
            flag = true;
            break;
        }
    }
    if (!flag)
        s = string(s.size(), 'A');

    cout << s << '\n';
}