#include <iostream>
#include <vector>
#include <numeric>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> a(k);
    for (int i = 0; i < k; i++)
        cin >> a[i];

    int result = 0;
    for (int i = 1; i < 1 << k; i++)
    {
        long long l = 1;
        for (int j = 0; j < k; j++)
        {
            if (i & (1 << j))
                l = lcm(l, a[j]);
            if (l > n)
                break;
        }
        result += n / l * (popcount(1u * i) & 1 ? +1 : -1);
    }
    cout << result << '\n';
}