#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MOD = 1'000'000'007;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(s.begin(), s.end());

    vector<int> pow2(n);
    pow2[0] = 1;
    for (int i = 1; i < n; i++)
        pow2[i] = pow2[i - 1] * 2 % MOD;

    int iSum = 0, jSum = 0;
    for (int i = 0; i < n - 1; i++)
        iSum = (iSum + 1LL * s[i] * (pow2[n - i - 1] - 1)) % MOD;
    for (int j = 1; j < n; j++)
        jSum = (jSum + 1LL * s[j] * (pow2[j] - 1)) % MOD;

    int result = (1LL * jSum - iSum + MOD) % MOD;
    cout << result << '\n';
}