#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        array<bool, 26> has = { false, };
        for (char c : s)
            has[c - 'a'] = true;

        int cnt = 0;
        for (int i = 0; i < 26; i++)
            cnt += has[i];
        result = max(result, cnt);
    }
    cout << result << '\n';
}