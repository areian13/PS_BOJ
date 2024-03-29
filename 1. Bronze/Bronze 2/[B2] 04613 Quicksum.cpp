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
        getline(cin, s);

        if (s == "#")
            break;

        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; i++)
            result += (s[i] == ' ' ? 0 : s[i] - 'A' + 1) * (i + 1);

        cout << result << '\n';
    }
}