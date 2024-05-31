#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    int sum = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        sum += a - b;

        int stand = max(sum - k, 0);
        result = max(result, stand);
    }
    cout << result << '\n';
}