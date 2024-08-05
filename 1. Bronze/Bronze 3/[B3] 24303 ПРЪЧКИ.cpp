#include <iostream>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a1, a2, a3, b1, b2, b3, l;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> l;

    int result = INT_MAX;
    for (int i = 0; i <= b1; i++)
    {
        for (int j = 0; j <= b2; j++)
        {
            for (int k = 0; k <= b3; k++)
            {
                if (a1 * i + a2 * j + a3 * k >= l)
                    result = min(result, i + j + k);
            }
        }
    }

    result = (result == INT_MAX ? 0 : result);
    cout << result << '\n';
}