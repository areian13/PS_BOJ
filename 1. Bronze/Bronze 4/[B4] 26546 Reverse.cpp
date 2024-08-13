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
        string str;
        int n, m;
        cin >> str >> n >> m;

        string result = str.substr(0, n) + str.substr(m);
        cout << result << '\n';
    }
}