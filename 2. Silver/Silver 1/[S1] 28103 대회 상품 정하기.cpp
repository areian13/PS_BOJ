#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long n, m, x;
    cin >> n >> m >> x;

    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
    {
        long long result = (i != m - 1 ? min(n, (x - n * a.back()) / (a[i] - a.back())) : n);
        cout << result << ' ';
        n -= result;
        x -= result * a[i];
    }
}