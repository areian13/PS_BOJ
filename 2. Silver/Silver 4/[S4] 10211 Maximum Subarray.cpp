#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int pSum = 0, mSum = 0;
        int result = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            pSum += a[i];
            result = max(result, pSum - mSum);
            mSum = min(mSum, pSum);
        }
        cout << result << '\n';
    }
}