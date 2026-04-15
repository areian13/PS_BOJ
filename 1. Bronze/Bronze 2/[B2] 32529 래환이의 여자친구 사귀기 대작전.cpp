#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Diet(int m, vector<int>& a)
{
    int n = a.size();
    int sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sum += a[i];
        if (sum >= m)
            return i + 1;
    }
    return -1;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int result = Diet(m, a);
    cout << result << '\n';
}