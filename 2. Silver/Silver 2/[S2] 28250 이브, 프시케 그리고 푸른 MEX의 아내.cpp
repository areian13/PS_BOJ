#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<long long, 3> cnt = { 0, };
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        cnt[min(a, 2)]++;
    }

    long long result = cnt[0] * ((cnt[0] - 1) / 2.0 + 2 * cnt[1] + cnt[2]);
    cout << result << '\n';
}