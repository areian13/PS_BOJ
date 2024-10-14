#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 10'000

int main()
{
    FastIO;

    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        array<int, MAX> cnt = { 0, };
        int maxCnt = 0;
        for (int i = 0; i < n * m; i++)
        {
            int p;
            cin >> p;
            p--;

            cnt[p]++;
            maxCnt = max(maxCnt, cnt[p]);
        }

        int nextMaxCnt = 0;
        for (int i = 0; i < MAX; i++)
        {
            if (cnt[i] != maxCnt)
                nextMaxCnt = max(nextMaxCnt, cnt[i]);
        }

        for (int i = 0; i < MAX; i++)
        {
            if (cnt[i] == nextMaxCnt)
                cout << i + 1 << ' ';
        }
        cout << '\n';
    }
}