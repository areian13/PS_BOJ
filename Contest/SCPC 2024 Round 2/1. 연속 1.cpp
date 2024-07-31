#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long Change0(vector<int>& arr)
{
    int start = 0;
    while (arr[start] == 0)
        start++;

    int end = arr.size() - 1;
    while (arr[end] == 0)
        end--;

    if (start >= end)
        return LLONG_MAX;

    long long result = 0;
    for (int i = start; i <= end; i++)
        result += (arr[i] == 0);
    return result;
}
long long Change1(vector<int>& arr)
{
    int n = arr.size();

    int maxLen = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt1 = 0;
        while (i < n && arr[i] == 1)
        {
            i++;
            cnt1++;
            cnt++;
        }
        maxLen = max(maxLen, cnt1);
    }
    return cnt - maxLen;
}

long long MinCost(vector<int>& arr, int s, int e)
{
    return min(Change0(arr) * s, Change1(arr) * e);
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int n, s, e;
        cin >> n >> s >> e;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        long long result = MinCost(arr, s, e);
        cout << "Case #" << t << endl;
        cout << result << endl;
    }
}