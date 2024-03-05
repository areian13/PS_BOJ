#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        vector<int> cnt(n, 0);
        for (int i = 0; i < m; i++)
        {
            int t;
            cin >> t;

            cnt[t - 1]++;
        }

        int result = 0;
        for (int i = 0; i < n; i++)
            result += (cnt[i] > 1);
        cout << result << '\n';
    }
}