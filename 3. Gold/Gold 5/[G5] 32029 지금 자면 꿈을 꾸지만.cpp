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
        int speed = a;
        int cnt = 0, cur = 0;
        bool wasSleep = false;
        for (int i : t)
        {
            if (!wasSleep && cur + b * x + speed - x <= i)
            {
                speed -= x;
                wasSleep = true;
                cur += b * x;
            }
            if (cur + speed <= i)
            {
                cur += speed;
                cnt++;
            }
        }
        result = max(result, cnt);
    }
    cout << result << '\n';
}