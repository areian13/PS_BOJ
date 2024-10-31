#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const array<double, 4> stick = { 0.80,1.00,1.20,0.80 };
const array<double, 4> kg = { 7.5,24.00,32.00,0.20 };

#define AMOUNT 85

int main()
{
    FastIO;

    int tc = 0;
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        double result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int s;
                cin >> s;

                result += (stick[j] - (j != 3 ? (kg[j] + 8) / AMOUNT : kg[j])) * s;
            }
        }
        printf("Case #%d: RM%.2lf\n", ++tc, result);
    }
}