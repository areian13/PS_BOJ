#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsYammy(string& s, vector<int> ind)
{
    int n = s.size();
    if (s[0] != 'a' || s[n - 1] != 'a')
        return false;

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            return false;
    }

    for (int i = 0; i < n; i++)
    {
        if (--ind[s[i] - 'a'] < 0)
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> ind(4);
    for (int i = 0; i < 4; i++)
        cin >> ind[i];

    string s;
    cin >> s;

    bool result = IsYammy(s, ind);
    cout << (result ? "Yes" : "No") << '\n';
}