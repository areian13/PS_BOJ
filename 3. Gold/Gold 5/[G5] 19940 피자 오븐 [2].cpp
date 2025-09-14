#include <iostream>
#include <array>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        int sixty = n / 60, ten = n % 60 / 10, one = n % 10;

        if (one > 5)
            ten++, one -= 10;
        if (ten > 3)
            sixty++, ten -= 6;
        if (ten < 0 && one == 5)
            ten++, one -= 10;

        array<int, 5> result = { 0, };
        result[0] = sixty;
        result[1 + (ten < 0)] = abs(ten);
        result[3 + (one < 0)] = abs(one);
        for (int i = 0; i < 5; i++)
            cout << result[i] << ' ';
        cout << '\n';
    }
}