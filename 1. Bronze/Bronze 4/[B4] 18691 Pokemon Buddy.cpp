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
        int g, c, e;
        cin >> g >> c >> e;

        int result = (g * 2 - 1) * max(e - c, 0);
        cout << result << '\n';
    }
}