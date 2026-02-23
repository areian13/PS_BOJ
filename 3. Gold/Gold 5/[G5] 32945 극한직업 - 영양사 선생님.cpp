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

    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(b.begin(), b.end(), greater<int>());

    vector<int> diff(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        diff[i]++;
        diff[min(i + b[i], n)]--;
    }

    int result = 0, inc = 0;
    for (int i = 0; i <= n; i++)
    {
        inc += diff[i];
        result = max(result, inc);
    }
    cout << result << '\n';
}