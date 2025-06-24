#include <iostream>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanSame(string& a, string& b)
{
    for (int i = 0; i < 9; i++)
    {
        if (b[i] != '*' && a[i] != b[i])
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    string c;
    int n;
    cin >> c >> n;

    vector<string> result;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (CanSame(s, c))
            result.push_back(s);
    }

    cout << result.size() << '\n';
    for (auto& s : result)
        cout << s << '\n';
}