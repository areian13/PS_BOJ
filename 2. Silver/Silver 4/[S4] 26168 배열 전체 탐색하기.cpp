#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int LowerBound(long long x, vector<long long>& a)
{
    int start = 0, end = a.size() - 1;

    int result = end + 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] < x)
            start = mid + 1;
        if (a[mid] >= x)
        {
            result = mid;
            end = mid - 1;
        }
    }
    return result;
}

int UpperBound(long long x, vector<long long>& a)
{
    int start = 0, end = a.size() - 1;

    int result = end + 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] <= x)
            start = mid + 1;
        if (a[mid] > x)
        {
            result = mid;
            end = mid - 1;
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    for (int tc = 1; tc <= m; tc++)
    {
        int q;
        cin >> q;

        if (q == 1)
        {
            long long k;
            cin >> k;

            int idx = LowerBound(k, a);
            cout << n - idx << '\n';
        }
        else if (q == 2)
        {
            long long k;
            cin >> k;

            int idx = UpperBound(k, a);
            cout << n - idx << '\n';
        }
        else if (q == 3)
        {
            long long i, j;
            cin >> i >> j;

            int idx1 = LowerBound(i, a);
            int idx2 = UpperBound(j, a);
            cout << idx2 - idx1 << '\n';
        }
    }
}