#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsVPS(string s)
{
    while (true)
    {
        int idx = s.find("()");
        if (idx == string::npos)
            break;
        s.replace(idx, 2, "");
    }

    return s.empty();
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string s;
        cin >> s;
      
        string result = (IsVPS(s) ? "YES" : "NO");
        cout << result << '\n';
    }
}