#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long CountCandy(long long x, vector<long long>& a)
{
    long long result = 0;
    for (long long t : a)
        result += max(t - x, 0ll);
    return result;
}

long long BS(long long k, vector<long long>& a)
{
    long long start = 0;
    long long end = *max_element(a.begin(), a.end());

    long long result = end;
    while (start < end)
    {
        long long mid = (start + end) / 2;
        long long candy = CountCandy(mid, a);

        if (candy > k)
            start = mid + 1;
        else
        {
            end = mid;
            result = mid;
        }
    }
    return result;
}

int main()
{
    FastIO;

    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long result = BS(k, a);
    cout << result << '\n';
}