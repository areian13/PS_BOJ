#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int a[3001], b[3001];
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    int ma = 1 << 29, mb = 1 << 29;
    int ans1 = 1;
    for (int i = 0; i < n; i++) {
        if (ma < a[i] && mb < b[i]) continue;
        if (ma > a[i] && mb > b[i]) {
            ma = a[i]; mb = b[i];
        }
        else {
            ma = a[i]; mb = b[i];
            ans1++;
        }
    }

    reverse(a,a+n);
    reverse(b,b+n);

    ma = 1 << 29, mb = 1 << 29;
    int ans2 = 1;
    for (int i = 0; i < n; i++) {
        if (ma < a[i] && mb < b[i]) continue;
        if (ma > a[i] && mb > b[i]) {
            ma = a[i]; mb = b[i];
        }
        else {
            ma = a[i]; mb = b[i];
            ans2++;
        }
    }

    cout << min(ans1, ans2);
}