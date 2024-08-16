#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsAllSame(string& s)
{
    char std = s[0];
    for (char c : s)
    {
        if (c != std)
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    string result = (IsAllSame(s) ? "Yes" : "No");
    cout << result << '\n';
}