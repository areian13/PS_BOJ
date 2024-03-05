#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n, c, k;
        cin >> n >> c >> k;

        if (n == 0 && c == 0 && k == 0)
            break;

        vector<int> cnt(k, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int x;
                cin >> x;

                cnt[x - 1]++;
            }
        }

        int minCnt = *min_element(cnt.begin(), cnt.end());
        for (int i = 0; i < k; i++)
        {
            if (cnt[i] == minCnt)
                cout << i + 1 << ' ';
        }
        cout << '\n';
    }
}