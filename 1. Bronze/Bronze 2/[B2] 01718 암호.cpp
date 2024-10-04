#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s, k;
    getline(cin, s) >> k;

    int n = s.size();
    int m = k.size();

    string result = "";
    for (int i = 0, j = 0; i < n; i++, j = (j + 1) % m)
    {
        if (s[i] == ' ')
            result += ' ';
        else
            result += (s[i] - (k[j] + 1) + 26) % 26 + 'a';
    }
    cout << result << '\n';
}