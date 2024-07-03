#include <iostream>
#include <array>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int price[3][2] = { { 30,40 },{ 35,30 },{ 40,20 } };

    while (true)
    {
        int c, d;
        cin >> c >> d;

        if (c == 0 && d == 0)
            break;

        int result = INT_MAX;
        for (int i = 0; i < 3; i++)
            result = min(result, c * price[i][0] + d * price[i][1]);
        cout << result << '\n';
    }
}