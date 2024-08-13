#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

char UnusedChar(string& str)
{
    array<bool, 26> isUsed = { false, };
    for (char c : str)
        isUsed[c - 'A'] = true;

    for (int i = 0; i < 26; i++)
    {
        if (!isUsed[i])
            return 'A' + i;
    }
    return '\0';
}

int main()
{
    FastIO;

    string str;
    cin >> str;

    char result = UnusedChar(str);
    cout << result << '\n';
}