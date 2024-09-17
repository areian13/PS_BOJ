#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void PrintLIS(int idx, int len, vector<int>& a, vector<int>& p)
{
    if (idx == -1)
        return;

    if (p[idx] == len)
    {
        PrintLIS(idx - 1, len - 1, a, p);
        cout << a[idx] << ' ';
    }
    else
        PrintLIS(idx - 1, len, a, p);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n), l(n, 0), p(n);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        auto it = lower_bound(l.begin(), l.begin() + result, a[i]);
        *it = a[i];
        p[i] = it - l.begin() + 1;

        if (it == l.begin() + result)
            result++;
    }

    cout << result << '\n';
    PrintLIS(n - 1, result, a, p);
    cout << '\n';
}