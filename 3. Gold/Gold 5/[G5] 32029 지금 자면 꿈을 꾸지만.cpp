#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    sort(t.begin(), t.end());

    int result = 0;
    for (int x = 0; x < a; x++)
    {
        int cnt = 0, cur = 0;
        int ta = a;
        bool wasSleep = false;
        for (int i : t)
        {
            if (!wasSleep && cur + (ta - x) + b * x <= i)
            {
                ta -= x;
                cur += b * x;
                wasSleep = true;
            }

            if (cur + ta <= i)
            {
                cur += ta;
                cnt++;
            }
        }
        result = max(result, cnt);
    }
    cout << result << '\n';
}