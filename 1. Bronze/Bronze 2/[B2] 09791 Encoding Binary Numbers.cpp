#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string s;
        cin >> s;

        if (s == "0")
            break;

        int n = s.size();
        string result = "";
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            while (i + j < n && s[i + j] == s[i])
                j++;
            result += to_string(j) + s[i];
            i += j - 1;
        }
        cout << result << '\n';
    }
}