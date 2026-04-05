#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 52;
const int MOD = 10'007;
vector<vector<int>> comb(MAX + 1, vector<int>(MAX + 1, 0));

int main()
{
    FastIO;

    for (int i = 0; i <= MAX; i++)
        comb[i][0] = 1;
    for (int i = 1; i <= MAX; i++)
    {
        for (int j = 1; j <= i; j++)
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
    }

    int n;
    cin >> n;

    int result = 0;
    for (int i = 1; i * 4 <= n; i++)
    {
        int v = comb[MAX / 4][i] * comb[MAX - i * 4][n - i * 4] % MOD;
        result = (result + (i & 1 ? +v : -v) + MOD) % MOD;
    }
    cout << result << '\n';
}