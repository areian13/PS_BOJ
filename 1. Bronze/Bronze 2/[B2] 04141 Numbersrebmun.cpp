#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

char cton(char c)
{
    c |= 32;
    if ('a' <= c && c <= 'c')
        return 2;
    if ('d' <= c && c <= 'f')
        return 3;
    if ('g' <= c && c <= 'i')
        return 4;
    if ('j' <= c && c <= 'l')
        return 5;
    if ('m' <= c && c <= 'o')
        return 6;
    if ('p' <= c && c <= 's')
        return 7;
    if ('t' <= c && c <= 'v')
        return 8;
    return 9;
}

string MakeNum(string& str)
{
    string result = "";
    for (char c : str)
        result += cton(c);
    return result;
}

bool IsPalindrome(string& str)
{
    string num = MakeNum(str);

    int n = num.size();
    int mid = n / 2;
    for (int i = 0; i <= mid - (n % 2 == 0); i++)
    {
        if (num[mid - i - (n % 2 == 0)] != num[mid + i])
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string str;
        cin >> str;

        string result = (IsPalindrome(str) ? "YES" : "NO");
        cout << result << '\n';
    }
}