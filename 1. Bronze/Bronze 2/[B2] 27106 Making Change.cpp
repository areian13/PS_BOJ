#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int p;
    cin >> p;

    int k = 100 - p;

    array<int, 4> coins = { 25,10,5,1 };
    array<int, 4> result;
    for (int i = 0; i < 4; i++)
    {
        result[i] = k / coins[i];
        k %= coins[i];
    }
    for (int i = 0; i < 4; i++)
        cout << result[i] << ' ';
    cout << '\n';
}