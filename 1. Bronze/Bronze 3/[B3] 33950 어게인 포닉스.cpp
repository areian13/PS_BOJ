#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        string s;
        cin >> s;

        int n = s.size();
        string result = "";
        for (int i = 0; i < n; i++)
        {
            if (s.substr(i, 2) == "PO")
                result += "PHO", i++;
            else
                result += s[i];
        }
        cout << result << '\n';
    }
}