#include <iostream>
#include <vector>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long result = 0;
    for (int i = 0; i < n / 2; i++)
    {
        int p = a[i], q = a[n - 1 - i];
        if (p > q) swap(p, q);

        int c = (q - p) / k;
        int s = c + (q - (p + c * k));
        int t = (c + 1) + (p + (c + 1) * k - q);
        result += min(s, t);
    }
    cout << result << '\n';
}