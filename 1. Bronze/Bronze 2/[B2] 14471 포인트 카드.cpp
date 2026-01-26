#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> a[i] >> b;
    }
    sort(a.begin(), a.end());

    int result = 0;
    for (int i = 1; i < m; i++)
        result += max(n - a[i], 0);
    cout << result << '\n';
}