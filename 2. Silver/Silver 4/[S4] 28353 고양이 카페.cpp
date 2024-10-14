#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> cat(n);
    for (int i = 0; i < n; i++)
        cin >> cat[i];
    sort(cat.begin(), cat.end());

    int result = 0;
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        if (cat[left] + cat[right] <= k)
        {
            result++;
            left++;
        }
        right--;
    }
    cout << result << '\n';
}