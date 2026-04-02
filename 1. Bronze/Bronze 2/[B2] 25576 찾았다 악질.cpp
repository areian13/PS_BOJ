#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> l(m);
    for (int j = 0; j < m; j++)
        cin >> l[j];

    int result = 0;
    for (int i = 1; i < n; i++)
    {
        int dt = 0;
        for (int j = 0; j < m; j++)
        {
            int k;
            cin >> k;
            dt += abs(l[j] - k);
        }
        result += (dt > 2'000);
    }

    cout << (result >= (n - 1) / 2. ? "YES" : "NO") << '\n';
}