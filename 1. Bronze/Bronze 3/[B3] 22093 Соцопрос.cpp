#include <iostream>
#include <array>
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
        int n, a, b;
        cin >> n >> a >> b;

        array<int, 2> result = { max(a - b, 0),min(a, n - b) };
        cout << result[0] << ' ' << result[1] << '\n';
    }
}