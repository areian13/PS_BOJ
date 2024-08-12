#include <iostream>
#include <cstdio>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        vector<int> coin(n);
        for (int i = 0; i < n; i++)
            cin >> coin[i];

        bool isGood = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (coin[i + 1] < coin[i] * 2)
                isGood = false;
        }

        printf("Denominations: ");
        for (int i = 0; i < n; i++)
            printf("%d ", coin[i]);
        printf("\n");

        printf("%s coin denominations!\n\n", (isGood ? "Good" : "Bad"));
    }
}