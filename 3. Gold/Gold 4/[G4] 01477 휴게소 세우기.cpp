#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountRestStop(int dist, vector<int>& location)
{
    int n = location.size() - 2;

    int result = 0;
    for (int i = 1; i <= n + 1; i++)
        result += (location[i] - location[i - 1] - 1) / dist;
    return result;
}

int PS(int m, int l, vector<int>& location)
{
    int start = 1;
    int end = l;

    int result = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int cnt = CountRestStop(mid, location);

        if (cnt > m)
            start = mid + 1;
        else
        {
            end = mid - 1;
            result = min(result, mid);
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n, m, l;
    cin >> n >> m >> l;

    vector<int> location(n + 2);
    location[0] = 0;
    location[n + 1] = l;
    for (int i = 1; i <= n; i++)
        cin >> location[i];
    sort(location.begin() + 1, location.end() - 1);

    int result = PS(m, l, location);
    cout << result << '\n';
}