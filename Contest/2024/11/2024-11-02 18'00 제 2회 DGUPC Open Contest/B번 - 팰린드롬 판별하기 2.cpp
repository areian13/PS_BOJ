#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MinQuery(string& s)
{
    int n = s.size();

    for (int i = 0; i < n / 2; i++)
    {
        char c1 = s[i];
        char c2 = s[n - 1 - i];

        if (c1 != '?' && c2 != '?' && c1 != c2)
            return 0;
    }

    int result = 0;
    for (int i = 0; i < n / 2; i++)
    {
        char c1 = s[i];
        char c2 = s[n - 1 - i];

        if (c1 != '?' && c1 == c2)
            continue;

        if (c1 == '?' && c2 == '?')
            result += 26;
        else if (c1 == '?' && c2 != '?')
            result++;
        else if (c2 == '?' && c1 != '?')
            result++;
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    int result = MinQuery(s);
    cout << result << '\n';
}