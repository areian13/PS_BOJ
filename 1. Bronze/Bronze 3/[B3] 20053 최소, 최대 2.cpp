#include <iostream>
#include <array>
#include <climits>
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
        int n;
        cin >> n;

        array<int, 2> result = { INT_MAX,INT_MIN };
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;

            result[0] = min(result[0], a);
            result[1] = max(result[1], a);
        }

        cout << result[0] << ' ' << result[1] << '\n';
    }
}