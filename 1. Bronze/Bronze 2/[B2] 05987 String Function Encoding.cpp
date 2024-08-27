#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, c;
        string s;
        cin >> n >> c >> s;

        for (int i = 0; i < c; i++)
            s = s.substr(n) + s;
        cout << s << '\n';
    }
}