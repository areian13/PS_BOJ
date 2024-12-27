#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int t, x, n;
    cin >> t >> x >> n;

    bool result = true;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        bool hasX = false;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;

            hasX |= (a == x);
        }
        result &= hasX;
    }

    if (result == true)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}