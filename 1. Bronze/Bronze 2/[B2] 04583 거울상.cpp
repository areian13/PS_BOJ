#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Mirror(string& s)
{
    static array<int, 26> mirror = { '\0', };
    static bool isInited = false;

    if (!isInited)
    {
        isInited = true;

        mirror['b' - 'a'] = 'd';
        mirror['d' - 'a'] = 'b';
        mirror['p' - 'a'] = 'q';
        mirror['q' - 'a'] = 'p';
        mirror['i' - 'a'] = 'i';
        mirror['o' - 'a'] = 'o';
        mirror['v' - 'a'] = 'v';
        mirror['w' - 'a'] = 'w';
        mirror['x' - 'a'] = 'x';
    }

    int n = s.size();
    string result(n, '\0');
    for (int i = 0; i < n; i++)
    {
        if (mirror[s[i] - 'a'] == '\0')
            return "INVALID";
        result[n - 1 - i] = mirror[s[i] - 'a'];
    }
    return result;
}

int main()
{
    FastIO;

    while (true)
    {
        string s;
        cin >> s;

        if (s == "#")
            break;

        string result = Mirror(s);
        cout << result << '\n';
    }
}