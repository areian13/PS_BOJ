#include <iostream>
#include <cstdio>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n;
        scanf("%d", &n);

        if (n == 0)
            break;

        int total = 0, night = 0;
        bool over120 = false;
        for (int i = 0; i < n; i++)
        {
            array<int, 4> t;
            for (int j = 0; j < 4; j++)
            {
                int h, m;
                scanf("%d:%d ", &h, &m);
                
                t[j] = h * 60 + m;
            }

            int time = t[3] - t[2];
            total += time;
            over120 |= (time > 120);
            if (t[3] <= t[0] || t[2] >= t[1]
                || t[0] - t[2] >= t[3] - t[0]
                || t[1] - t[2] <= t[3] - t[1])
                night += time;
        }

        bool result = (total >= 50 * 60 && night >= 10 * 60 && !over120);
        if (result == true)
            cout << "PASS" << '\n';
        else
            cout << "NON" << '\n';
    }
}