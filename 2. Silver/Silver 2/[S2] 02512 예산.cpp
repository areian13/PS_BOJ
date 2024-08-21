#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int SumBudget(int limit, vector<int>& budgets)
{
    int result = 0;
    for (int budget : budgets)
        result += min(budget, limit);
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> budgets(n);
    for (int i = 0; i < n; i++)
        cin >> budgets[i];

    int m;
    cin >> m;

    int start = 0;
    int end = *max_element(budgets.begin(), budgets.end());
    int result = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        int sum = SumBudget(mid, budgets);
        if (sum <= m)
        {
            result = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    cout << result << '\n';
}