#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<bool> switchs(n + 1);
    for (int i = 1; i <= n; i++)
    {
        bool isOn;
        cin >> isOn;

        switchs[i] = isOn;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int g, k;
        cin >> g >> k;

        if (g == 1)
        {
            for (int i = k; i <= n; i += k)
                switchs[i] = !switchs[i];
        }
        else
        {
            int s = 1;
            switchs[k] = !switchs[k];
            while (1 <= k - s && k + s <= n)
            {
                if (switchs[k - s] != switchs[k + s])
                    break;

                switchs[k - s] = !switchs[k - s];
                switchs[k + s] = !switchs[k + s];
                s++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << switchs[i] << ' ';
        if (i % 20 == 0)
            cout << '\n';
    }
}