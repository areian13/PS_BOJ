#include <iostream>
#include <cstdio>
#include <string>

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

        double result = 0;
        for (int i = 0; i < n; i++)
        {
            string ingred;
            int cnt;
            double price;
            cin >> ingred >> cnt >> price;

            result += cnt * price;
        }
        printf("$%.2lf\n", result);
    }
}