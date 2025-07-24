#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;


int Sum(int i, int j, vector<int>& preSum)
{
    return preSum[j] - preSum[i - 1];
}

int main()
{
    FastIO;

    int t, n;
    cin >> t >> n;

    vector<int> aPre(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        aPre[i + 1] = aPre[i] + a;
    }

    int m;
    cin >> m;

    vector<int> bPre(m + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        bPre[i + 1] = bPre[i] + b;
    }

    vector<int> bSum(m * (m + 1) / 2);
    unordered_map<int, int> UM;
    for (int i = 1, idx = 0; i <= m; i++)
    {
        for (int j = i; j <= m; j++, idx++)
        {
            bSum[idx] = Sum(i, j, bPre);
            UM[bSum[idx]]++;
        }
    }
    sort(bSum.begin(), bSum.end());

    long long result = 0;
    for (int i = 1, idx = 0; i <= n; i++)
    {
        for (int j = i; j <= n; j++, idx++)
        {
            int lValue = t - Sum(i, j, aPre);

            int start = 0;
            int end = bSum.size() - 1;

            while (start <= end)
            {
                int mid = (start + end) / 2;

                if (lValue > bSum[mid])
                    start = mid + 1;
                else if (lValue < bSum[mid])
                    end = mid - 1;
                else
                {
                    result += UM[bSum[mid]];
                    break;
                }
            }
        }
    }

    cout << result << '\n';
}