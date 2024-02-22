#include <iostream>
#include <vector>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> h(n);
    array<int, 3>  cnt = { 0,0,0 };
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        cnt[h[i] - 1]++;
    }

    int u, d;
    cin >> u >> d;

    if (cnt[0] + cnt[2] < u || cnt[1] + cnt[2] < d)
    {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    string result(n, '\0');
    for (int i = 0; i < n; i++)
    {
        switch (h[i])
        {
        case 1:
            u--;
            cnt[0]--;
            result[i] = 'U';
            break;

        case 2:
            d--;
            cnt[1]--;
            result[i] = 'D';
            break;

        case 3:
            if (cnt[0] + cnt[2] - u <= cnt[1] + cnt[2] - d)
            {
                u--;
                cnt[2]--;
                result[i] = 'U';
            }
            else
            {
                d--;
                cnt[2]--;
                result[i] = 'D';
            }
            break;
        }
    }
    cout << result << '\n';
}