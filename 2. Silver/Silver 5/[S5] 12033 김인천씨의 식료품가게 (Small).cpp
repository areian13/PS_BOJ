#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin>>tc;

    for (int t = 1; t <= tc; t++)
    {
        int n;
        cin>>n;

        unordered_map<int, int> cntDiscountedPrice;
        vector<int> result;
        for (int i = 0; i < n * 2; i++)
        {
            int p;
            cin>>p;

            if (p % 4 == 0 && cntDiscountedPrice[p / 4 * 3] > 0)
            {
                result.push_back(p / 4 * 3);
                cntDiscountedPrice[p / 4 * 3]--;
            }
            else
                cntDiscountedPrice[p]++;
        }

        printf("Case #%d: ", t);
        for (int i = 0; i < n; i++)
            printf("%d ", result[i]);
        printf("\n");
    }
}