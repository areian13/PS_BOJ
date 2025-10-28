#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Dia
{
    double w, c;

    friend bool operator < (const Dia& a, const Dia& b)
    {
        return a.w < b.w && a.c > b.c;
    }
};

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        vector<Dia> dias(n);
        for (auto& [w, c] : dias)
            cin >> w >> c;

        vector<int> dp(n, 1);
        int result = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dias[j] < dias[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result, dp[i]);
        }
        cout << result << '\n';
    }
}