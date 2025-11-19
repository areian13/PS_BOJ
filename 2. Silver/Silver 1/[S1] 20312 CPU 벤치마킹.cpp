#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MOD = 1'000'000'007;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0, pre = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int m;
        cin >> m;

        pre = (1LL * pre * m + m) % MOD;
        result = (1LL * result + pre) % MOD;
    }
    cout << result << '\n';
}