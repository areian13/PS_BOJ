#include <iostream>
#include <climits>
#include <cmath>

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

        int minGap = INT_MAX;
        int result = 0;
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;

            int gap = abs(2023 - a);
            if (gap < minGap)
            {
                minGap = gap;
                result = i;
            }
        }
        cout << result << '\n';
    }
}