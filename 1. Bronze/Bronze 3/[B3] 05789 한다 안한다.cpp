#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string str;
        cin >> str;

        string result = "Do-it";
        if (str[str.size() / 2 - 1] != str[str.size() / 2])
            result += "-Not";

        cout << result << '\n';
    }
}