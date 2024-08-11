#include <iostream>
#include <vector>

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

    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[i - 1] != 1)
            result += arr[i];
    }
    cout << result << '\n';
}