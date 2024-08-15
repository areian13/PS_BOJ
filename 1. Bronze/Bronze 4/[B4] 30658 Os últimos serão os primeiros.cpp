#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = n - 1; i >= 0; i--)
            cout << a[i] << '\n';
        cout << 0 << '\n';
    }
}