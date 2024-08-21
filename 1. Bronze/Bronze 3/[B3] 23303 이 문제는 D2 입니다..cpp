#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsD2(string& s)
{
    int n = s.size();

    for (int i = 0; i < n - 1; i++)
    {
        if ((s[i] & ~32) == 'D' && s[i + 1] == '2')
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    string s;
    getline(cin, s);

    string result = (IsD2(s) ? "D2" : "unrated");
    cout << result << '\n';
}