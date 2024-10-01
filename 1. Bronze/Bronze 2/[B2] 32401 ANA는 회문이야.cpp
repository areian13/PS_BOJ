#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    string ana = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A' || s[i] == 'N')
            ana += s[i];
    }

    int m = ana.size();

    int result = 0;
    for (int i = 0; i < m - 2; i++)
        result += (ana.substr(i, 3) == "ANA");
    cout << result << '\n';
}