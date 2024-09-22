#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsPalin(string& s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        cnt += IsPalin(s);
    }

    int result = cnt * (cnt - 1);
    cout << result << '\n';
}