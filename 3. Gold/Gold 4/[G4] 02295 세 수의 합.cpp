#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool BS(int num, int start, int end, vector<int>& u)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (u[mid] < num)
            start = mid + 1;
        else if (num < u[mid])
            end = mid - 1;
        else
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> u(n);
    for (int i = 0; i < n; i++)
        cin >> u[i];
    sort(u.begin(), u.end());

    vector<int> sum((n) * (n + 1) / 2);
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++, idx++)
            sum[idx] = u[i] + u[j];
    }
    sort(sum.begin(), sum.end());

    int result = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            if (BS(u[i] - u[j], 0, sum.size() - 1, sum))
            {
                result = u[i];
                goto QUIT_LOOP;
            }
        }
    }
QUIT_LOOP:
    cout << result << '\n';
}