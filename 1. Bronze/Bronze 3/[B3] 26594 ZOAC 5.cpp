#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int NZoac(string& s)
{
    int n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
            return i + 1;
    }
    return n;
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    int result = NZoac(s);
    cout << result << '\n';
}