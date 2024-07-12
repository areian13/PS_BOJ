#include <iostream>
#include <cstdio>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountInsertB(string& s)
{
    int n = s.size();

    int result = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (i < n - 2 && s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'A')
            result += 1;
        else if (s[i] == 'A' && s[i + 1] == 'A')
            result += 2;
    }
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int n;
        string s;
        cin >> n >> s;

        int result = CountInsertB(s);
        cout << "Case #" << t << endl;
        cout << result << endl;
    }
}