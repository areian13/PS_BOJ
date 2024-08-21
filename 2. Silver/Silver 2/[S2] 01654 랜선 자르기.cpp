#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long GetTree(long long x, vector<long long>& a)
{
    long long result = 0;
    for (long long lan : a)
        result += lan / x;
    return result;
}

long long BS(long long n, vector<long long>& a)
{
    long long start = 1;
    long long end = *max_element(a.begin(), a.end());

    long long result = 0;
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long tree = GetTree(mid, a);

        if (tree >= n)
        {
            start = mid + 1;
            result = max(result, mid);
        }
        else
            end = mid - 1;
    }
    return result;
}

int main()
{
    FastIO;

    long long k, n;
    cin >> k >> n;

    vector<long long> a(k);
    for (int i = 0; i < k; i++)
        cin >> a[i];

    long long result = BS(n, a);
    cout << result << '\n';
}