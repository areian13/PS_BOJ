#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n;
        float m;
        cin >> n >> m;

        if (n == 0 && m == 0.00f)
            break;

        int money = m * 100 + 0.005f;
        vector<int> dp(money + 1);
        while (n--)
        {
            int c;
            float p;
            cin >> c >> p;

            int price = p * 100 + 0.005f;
            for (int i = price; i <= money; i++)
                dp[i] = max(dp[i], dp[i - price] + c);
        }
        cout << dp[money] << '\n';
    }
}