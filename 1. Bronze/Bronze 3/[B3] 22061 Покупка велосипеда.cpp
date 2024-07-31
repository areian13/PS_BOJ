#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        c -= 2 * b;
        c = max(c, (int)(c % 2 != 0));

        string result = (c <= a ? "YES" : "NO");
        cout << result << '\n';
    }
}