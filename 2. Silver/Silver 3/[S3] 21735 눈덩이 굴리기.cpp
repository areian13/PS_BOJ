#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MaxSnow(int d, int s, int m, vector<int>& a)
{
    int n = a.size();
    if (d >= n - 1 || m == 0) return s;

    int p = MaxSnow(d + 1, s + a[d + 1], m - 1, a);
    int q = d + 2 >= n ? 0 : MaxSnow(d + 2, s / 2 + a[d + 2], m - 1, a);
    return max(p, q);
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int result = MaxSnow(-1, 1, m, a);
    cout << result << '\n';
}