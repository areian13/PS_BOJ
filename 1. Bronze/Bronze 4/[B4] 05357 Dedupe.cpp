#include <iostream>

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

        int n = str.size();

        string result;
        result += str[0];
        for (int i = 1; i < n; i++)
        {
            if (str[i] != str[i - 1])
                result += str[i];
        }
        cout << result << '\n';
    }
}