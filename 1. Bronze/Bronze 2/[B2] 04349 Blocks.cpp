#include <iostream>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int c;
    cin >> c;

    while (c--)
    {
        int n;
        cin >> n;

        int result = INT_MAX;
        for (int x = 1; x <= n; x++)
        {
            for (int y = 1; x * y <= n; y++)
            {
                for (int z = 1; x * y * z <= n; z++)
                {
                    if (x * y * z == n)
                        result = min(result, 2 * (x * y + y * z + z * x));
                }
            }
        }
        cout << result << '\n';
    }
}