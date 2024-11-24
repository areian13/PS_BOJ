#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsMo(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    FastIO;

    string s;
    getline(cin, s);

    string result = "";
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (IsMo(s[i]))
            i += 2;
        result += s[i];
    }
    cout << result << '\n';
}