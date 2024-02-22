#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int q;
    cin >> q;

    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1)
        {
            int k;
            cin >> k;

            int result = 0;
            for (int i = l; i <= r; i++)
                result += (a[i] == k);
            cout << result << '\n';
        }
        else
        {
            for (int i = l; i <= r; i++)
                a[i] = 0;
        }
    }
}