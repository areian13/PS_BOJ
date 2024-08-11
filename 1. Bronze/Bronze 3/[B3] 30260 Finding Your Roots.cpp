#include <iostream>
#include <cstdio>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int k;
    cin >> k;

    for (int x = 1; x <= k; x++)
    {
        int l, n;
        cin >> l >> n;

        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> p[i];

        int result = 1;
        while (p[l] != 0)
        {
            result++;
            l = p[l];
        }
        printf("Data Set %d:\n%d\n\n", x, result);
    }
}