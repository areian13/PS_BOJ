#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int OctValue(string s, unordered_map<char, int>& v)
{
    reverse(s.begin(), s.end());
    int result = 0;
    int p = 1;
    for (char c : s)
    {
        result += v[c] * p;
        p *= 8;
    }
    return result;
}

int main()
{
    FastIO;

    unordered_map<char, int> v;
    v['-'] = 0;
    v['\\'] = 1;
    v['('] = 2;
    v['@'] = 3;
    v['?'] = 4;
    v['>'] = 5;
    v['&'] = 6;
    v['%'] = 7;
    v['/'] = -1;

    while (true)
    {
        string s;
        cin >> s;

        if (s == "#")
            break;

        int result = OctValue(s, v);
        cout << result << '\n';
    }
}