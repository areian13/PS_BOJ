#include <iostream>
#include <vector>

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

    int result = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < m && a[i] - b[j] >= 0)
        {
            a[i] -= b[j];
            j++;
        }

        result += a[i];
    }
    cout << result << '\n';
}