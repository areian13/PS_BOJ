#include <iostream>
#include <cstdio>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n, l, h;
        cin >> n >> l >> h;

        vector<int> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];

        int result = -1;
        for (int i = l; i <= h; i++)
        {
            bool can = true;
            for (int j = 0; j < n; j++)
                can &= (s[j] % i == 0 || i % s[j] == 0);

            if (can)
            {
                result = i;
                break;
            }
        }
        
        printf("Case #%d: ", tc);
        if (result == -1)
            printf("NO\n");
        else
            printf("%d\n", result);
    }
}