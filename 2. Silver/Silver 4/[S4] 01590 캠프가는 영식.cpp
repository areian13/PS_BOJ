#include <iostream>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, t;
    cin >> n >> t;

    int result = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int s, d, c;
        cin >> s >> d >> c;

        for (int j = 0; j < c; j++)
        {
            if (t <= s + d * j)
                result = min(result, (s + d * j) - t);
        }
    }
    result = (result != INT_MAX ? result : -1);

    cout << result << '\n';
}