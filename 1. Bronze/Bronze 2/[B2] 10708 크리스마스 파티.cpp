#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];

    vector<int> result(n, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int b;
            cin >> b;

            result[j] += (a[i] == b);
            result[a[i] - 1] += (a[i] != b);
        }
    }

    for (int i = 0; i < n; i++)
        cout << result[i] << '\n';
}