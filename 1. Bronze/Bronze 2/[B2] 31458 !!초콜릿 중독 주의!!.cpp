#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int NotFactorial(string& s)
{
    int n = s.size();
    int p = -1, v = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '!')
            p = i, v = s[i] - '0';
    }

    if (p != n - 1) v = 1;
    return v ^ (p & 1);
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int i = 1; i <= TC; i++)
    {
        string s;
        cin >> s;

        int result = NotFactorial(s);
        cout << result << '\n';
    }
}