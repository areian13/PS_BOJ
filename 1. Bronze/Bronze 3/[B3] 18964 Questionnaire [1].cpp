#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<int> mkPair(vector<int>& a)
{
    int n = a.size();

    int m = 1;
    while (true)
    {
        vector<int> cnt(m, 0);
        for (int i = 0; i < n; i++)
            cnt[a[i] % m]++;

        for (int k = 0; k < m; k++)
        {
            if (cnt[k] >= n / 2)
                return { m,k };
        }
        m++;
    }
    return { -1,-1 };
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> result = mkPair(a);
    cout << result[0] << ' ' << result[1] << '\n';
}