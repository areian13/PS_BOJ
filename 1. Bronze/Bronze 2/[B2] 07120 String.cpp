#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    cin >> s;

    string result = "";
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != s[i + 1])
            result += s[i];
    }
    cout << result << '\n';
}