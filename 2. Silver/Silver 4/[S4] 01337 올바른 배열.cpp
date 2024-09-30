#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = arr[i]; j < arr[i] + 5; j++)
        {
            if (i + cnt < n && j == arr[i + cnt])
                cnt++;
        }
        result = max(result, cnt);
    }
    result = max(5 - result, 0);
    cout << result << '\n';
}