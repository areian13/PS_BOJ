#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc = 3;
    while (tc--)
    {
        string s;
        cin >> s;

        int result = 1;
        int cnt = 1;
        for (int i = 0; i < 7; i++)
        {
            if (s[i] == s[i + 1])
                cnt++;
            else
                cnt = 1;
            result = max(result, cnt);
        }
        cout << result << '\n';
    }
}