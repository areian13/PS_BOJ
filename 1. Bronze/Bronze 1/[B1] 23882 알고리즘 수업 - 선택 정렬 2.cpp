#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool SwapK(int k, vector<int>& a)
{
    int n = a.size();
    for (int i = n - 1; i >= 1; i--)
    {
        int j = max_element(a.begin(), a.begin() + i + 1) - a.begin();
        if (i != j)
            k--, swap(a[i], a[j]);

        if (k == 0)
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bool sorted = SwapK(k, a);
    if (sorted)
        cout << -1 << '\n';
    else
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
}