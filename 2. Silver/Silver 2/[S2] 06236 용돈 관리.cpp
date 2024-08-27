#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountWithdraw(int k, vector<int>& spend)
{
    int n = spend.size();

    int money = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (money < spend[i])
        {
            money = k;
            result++;
        }
        money -= spend[i];
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;


    vector<int> spend(n);
    for (int i = 0; i < n; i++)
        cin >> spend[i];

    int start = *max_element(spend.begin(), spend.end());
    int end = accumulate(spend.begin(), spend.end(), 0);
    int result = end;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int cnt = CountWithdraw(mid, spend);

        if (cnt > m)
            start = mid + 1;
        else
        {
            result = min(result, mid);
            end = mid - 1;
        }
    }
    cout << result << '\n';
}