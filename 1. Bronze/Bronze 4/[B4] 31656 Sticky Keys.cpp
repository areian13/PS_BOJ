#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    getline(cin, s);

    int n = s.size();

    string result = "";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1 || s[i] != s[i + 1])
            result += s[i];
    }
    cout << result << '\n';
}