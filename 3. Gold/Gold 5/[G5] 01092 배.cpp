#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> crane(n + 1);
    for (int i = 0; i < n; i++)
        cin >> crane[i];
    crane[n] = INT_MAX;
    sort(crane.begin(), crane.end());

    int m;
    cin >> m;

    vector<int> freight(m);
    for (int i = 0; i < m; i++)
        cin >> freight[i];
    sort(freight.begin(), freight.end(), greater<int>());

    vector<int> workOrder(n + 1, 0);
    workOrder[n] = INT_MAX;

    int result = -1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == n - 1 && freight[i] > crane[j])
                goto IS_IMPOSSIBLE;
            if (freight[i] <= crane[j] && (freight[i] > crane[j + 1] || freight[i] <= crane[j + 1] && workOrder[j] < workOrder[j + 1]))
            {
                workOrder[j]++;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        result = max(result, workOrder[i]);
IS_IMPOSSIBLE:
    cout << result << '\n';
}