#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> a(max(n, m), 0), b(max(n, m), 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int result = 0;
    for (int i = 0; i < max(n, m); i++)
        result = max(result, b[i] - a[i]);
    cout << result << '\n';
}