#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define COIN_CNT 8

array<string, COIN_CNT> coins = { "TTT","TTH","THT","THH","HTT","HTH","HHT","HHH" };

int SameCoin(string coin)
{
    for (int i = 0; i < COIN_CNT; i++)
    {
        if (coins[i] == coin)
            return i;
    }
    return -1;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string coin;
        cin >> coin;

        int n = coin.size();
        array<int, COIN_CNT> result = { 0, };
        for (int i = 0; i < n - 2; i++)
            result[SameCoin(coin.substr(i, 3))]++;
       
        for (int i = 0; i < COIN_CNT; i++)
            cout << result[i] << ' ';
        cout << '\n';
    }
}