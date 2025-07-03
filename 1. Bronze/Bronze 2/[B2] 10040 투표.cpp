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

    vector<int> cnt(n);
    for (int i = 0; i < m; i++)
    {
        int k = 0;
        for (int j = 0; j < n; j++)
        {
            if (b[i] >= a[j])
            {
                k = j;
                break;
            }
        }
        cnt[k]++;
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] >= cnt[result])
            result = i;
    }
    cout << result + 1 << '\n';
}