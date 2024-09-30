#include <iostream>
#include <vector>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int result = accumulate(a.begin(), a.end(), 0)
        - accumulate(b.begin(), b.end(), 0);
    cout << result << '\n';
}