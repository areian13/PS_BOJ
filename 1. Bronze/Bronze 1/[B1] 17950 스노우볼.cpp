#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MOD = 1'000'000'007;

int main()
{
    FastIO;

    int h, x;
    cin >> h >> x;

    int v = x;
    int result = 0;
    for (int i = 0; i < h; i++)
    {
        int c;
        cin >> c;

        result = (result + 1LL * v * c) % MOD;
        v = (1LL * v * x) % MOD;
    }
    cout << result << '\n';
}