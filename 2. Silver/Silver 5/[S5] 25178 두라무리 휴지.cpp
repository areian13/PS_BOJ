#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsMo(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool IsDuramuri(string& a, string& b)
{
    int n = a.size();
    if (n != b.size())
        return false;
    if (a[0] != b[0] || a[n - 1] != b[n - 1])
        return false;

    string s, t;
    for (int i = 0; i < n; i++)
    {
        if (!IsMo(a[i])) s += a[i];
        if (!IsMo(b[i])) t += b[i];
    }
    if (s != t)
        return false;

    s = a, t = b;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

int main()
{
    FastIO;

    int n;
    string a, b;
    cin >> n >> a >> b;

    bool result = IsDuramuri(a, b);
    cout << (result ? "YES" : "NO") << '\n';
}