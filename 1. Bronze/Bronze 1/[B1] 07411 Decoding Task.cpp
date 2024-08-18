#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int GetDec(char c)
{
    if ('0' <= c && c <= '9')
        return c - '0';
    return c - 'A' + 10;
}

int GetValue(string& str, int idx)
{
    return 16 * GetDec(str[2 * idx]) + GetDec(str[2 * idx + 1]);
}

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    int n = a.size() / 2;

    vector<int> code(n + 1);
    code[0] = 32 ^ GetValue(b, 0);
    for (int i = 1; i <= n; i++)
        code[i] = code[i - 1] ^ GetValue(a, i - 1) ^ GetValue(b, i);

    string result = "";
    string hex = "0123456789ABCDEF";
    for (int x : code)
    {
        result += hex[x / 16];
        result += hex[x % 16];
    }
    cout << result << '\n';
}