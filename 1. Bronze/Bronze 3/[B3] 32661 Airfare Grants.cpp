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

    int minP = INT_MAX;
    int maxP = 0;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        minP = min(minP, p);
        maxP = max(maxP, p);
    }

    int result = max(minP - maxP / 2, 0);
    cout << result << '\n';
}