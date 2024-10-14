#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    int q;
    cin >> q;

    vector<bool> isOn(n, true);
    cout << sum << '\n';
    while (q--)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int i, x;
            cin >> i >> x;

            sum += (x - a[i - 1]) * isOn[i - 1];
            a[i - 1] = x;
        }
        else
        {
            int i;
            cin >> i;

            isOn[i - 1] = !isOn[i - 1];
            if (!isOn[i - 1])
                sum -= a[i - 1];
            else
                sum += a[i - 1];
        }
        cout << sum << '\n';
    }
}