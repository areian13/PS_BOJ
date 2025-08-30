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

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i <= m; i++)
    {
        int j = 0;
        while (j + 1 < n)
        {
            if (a[j] % i > a[j + 1] % i)
                swap(a[j], a[j + 1]);
            j++;
        }
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << '\n';
}