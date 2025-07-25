#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, s;
    cin >> n >> s;

    vector<int> arr(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int low = 0;
    int high = 0;
    int sum = 0;
    int result = INT_MAX;
    while (low <= high && high <= n)
    {
        if (sum < s)
            sum += arr[high++];
        else
        {
            result = min(result, high - low);
            sum -= arr[low++];
        }
    }

    if (result != INT_MAX)
        cout << result << '\n';
    else
        cout << 0 << '\n';
}