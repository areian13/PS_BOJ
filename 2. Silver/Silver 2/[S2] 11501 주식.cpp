#include <iostream>
#include <vector>
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

        vector<int> stocks(n);
        for (int i = 0; i < n; i++)
            cin >> stocks[i];

        long long result = 0;
        int maxStock = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            maxStock = max(maxStock, stocks[i]);
            result += maxStock - stocks[i];
        }
        cout << result << '\n';
    }
}