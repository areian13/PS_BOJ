#include <iostream>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsSub(string& s, string& p)
{
    int n = s.size();
    int m = p.size();

    vector<int> fail(m, 0);
    for (int i = 1, j = 0; i < m; i++)
    {
        while (j > 0 && p[i] != p[j])
            j = fail[j - 1];
        if (p[i] == p[j])
            fail[i] = ++j;
    }

    for (int i = 0, j = 0; i < n; i++)
    {
        while (j > 0 && s[i] != p[j])
            j = fail[j - 1];

        if (s[i] == p[j])
        {
            if (j == m - 1)
                return true;
            else
                j++;
        }
    }
    return false;
}

int main()
{
    FastIO;

    string s, p;
    cin >> s >> p;

    bool result = IsSub(s, p);
    cout << result << '\n';
}