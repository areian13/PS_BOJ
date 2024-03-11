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

    vector<int> h(n);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        k += h[i];
    }
    k /= n;

    int result = 0;
    for (int i = 0; i < n; i++)
        result += max(h[i] - k, 0);
    cout << result << '\n';
}