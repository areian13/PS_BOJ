#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int cur;
    cin >> cur;

    int m = 0, l = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int nxt;
        cin >> nxt;

        m += max(cur - nxt, 0);
        l += max(nxt - cur, 0);

        cur = nxt;
    }
    cout << m << ' ' << l << '\n';
}