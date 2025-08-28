#include <iostream>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int maxT = 0, minB = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int t, b;
        cin >> t >> b;

        maxT = max(maxT, t);
        minB = min(minB, b);
    }

    int result = maxT * minB % 7 + 1;
    cout << result << '\n';
}