#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int StarCode(string& s)
{
    int sum = 0;
    int t = 0;
    for (int i = 0; i < 12; i++)
    {
        if (s[i] == '*')
            t = (i % 2 ? 3 : 1);
        else
            sum += (s[i] - '0') * (i % 2 ? 3 : 1);
    }

    for (int i = 0; i < 10; i++)
    {
        int v = 10 - (sum + i * t) % 10;
        if (v == 10)
            v = 0;
        if (v == s[12] - '0')
            return i;
    }
    return -1;
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    int result = StarCode(s);
    cout << result << '\n';
}