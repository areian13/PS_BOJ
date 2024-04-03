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

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    sort(x.begin(), x.end(), greater<int>());

    int result = x[k - 1];
    cout << result << '\n';
}