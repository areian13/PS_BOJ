#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int la = n, ra = 0, lp = n, rp = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        if (a == 1)
        {
            la = min(la, i);
            ra = i;
        }
        else
        {
            lp = min(lp, i);
            rp = i;
        }

        result = max({ result, ra - lp,rp - la });
    }
    cout << result << '\n';
}