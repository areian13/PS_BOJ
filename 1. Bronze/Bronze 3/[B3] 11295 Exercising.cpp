#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc = 0;
    while (true)
    {
        int stride;
        cin >> stride;

        if (stride == 0)
            break;

        printf("User %d\n", ++tc);

        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int dist;
            cin >> dist;

            double result = dist * stride / 100'000.0;
            printf("%.5lf\n", result);
        }
    }
}