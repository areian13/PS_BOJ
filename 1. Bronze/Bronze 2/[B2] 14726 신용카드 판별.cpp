#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsValid(string& s)
{
    int sum = 0;
    for (int i = 0; i < 16; i++)
    {
        int v = s[i] - '0';
        if (~i & 1)
        {
            v *= 2;
            if (v >= 10)
                v = v / 10 + v % 10;
        }
        sum += v;
    }
    return (sum % 10 == 0);
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

        bool result = IsValid(s);
        cout << (result ? 'T' : 'F') << '\n';
    }
}