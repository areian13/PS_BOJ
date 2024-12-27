#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m, a;
    cin >> n >> m >> a;
    a--;

    while (true)
    {
        int k;
        cin >> k;

        if (k == m / 2 + 1)
            break;

        a = (a + k - (m / 2 + 1) + n) % n;
        cout << a + 1 << '\n';

    }
    cout << 0 << '\n';
}