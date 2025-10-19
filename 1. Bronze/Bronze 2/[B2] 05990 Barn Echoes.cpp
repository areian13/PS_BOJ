#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int SameSufPre(string& a, string& b)
{
    int n = a.size(), m = b.size();
    int result = 0;
    for (int i = 0; i < min(n, m); i++)
    {
        if (a.substr(0, i + 1) == b.substr(m - i - 1))
            result = i + 1;
    }
    return result;
}

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    int result = max(SameSufPre(a, b), SameSufPre(b, a));
    cout << result << '\n';
}