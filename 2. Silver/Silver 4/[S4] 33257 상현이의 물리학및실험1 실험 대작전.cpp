#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, e;
    cin >> n >> e;

    vector<int> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];
    sort(d.begin(), d.end());

    int result = 1;
    for (int i = 1; i < n; i++)
        result += (d[i - 1] + e <= d[i]);
    cout << result << '\n';
}