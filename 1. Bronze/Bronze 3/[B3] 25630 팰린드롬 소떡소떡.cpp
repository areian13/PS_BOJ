#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MinMagic(string& s)
{
    int n = s.size();

    int result = 0;
    for (int i = 0; i < n / 2; i++)
        result += (s[i] != s[n - 1 - i]);
    return result;
}

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    int result = MinMagic(s);
    cout << result << '\n';
}