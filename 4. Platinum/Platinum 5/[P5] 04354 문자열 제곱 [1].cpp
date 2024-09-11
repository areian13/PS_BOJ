#include <iostream>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int SqrtStr(string& s)
{
    int n = s.size();

    vector<int> fail(n, 0);
    for (int i = 1, j = 0; i < n; i++)
    {
        while (j > 0 && s[i] != s[j])
            j = fail[j - 1];
        if (s[i] == s[j])
            fail[i] = ++j;
    }

    if (n % (n - fail[n - 1]) != 0)
        return 1;
    return n / (n - fail[n - 1]);
}

int main()
{
    FastIO;

    while (true)
    {
        string s;
        cin >> s;

        if (s == ".")
            break;

        int result = SqrtStr(s);
        cout << result << '\n';
    }
}