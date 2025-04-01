#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<bool, 500'001> sosu;
array<int, 10'001> nofPrice = { 0, };
array<long long, 500'001> cnt = { 1,0, };

int main()
{
    FastIO;

    fill(sosu.begin(), sosu.end(), true);
    sosu[0] = sosu[1] = false;
    for (int i = 2; i <= 500'000; i++)
    {
        if (!sosu[i])
            continue;
        for (int j = 2; i * j <= 500'000; j++)
            sosu[i * j] = false;
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nofPrice[a]++;
    }

    for (int i = 10'000; i > 0; i--)
    {
        if (nofPrice[i] == 0)
            continue;
        for (int j = 500'000; j > 0; j--)
        {
            for (int k = 1; k <= nofPrice[i]; k++)
            {
                if (j < i * k)
                    break;
                cnt[j] += cnt[j - i * k];
            }
        }
    }

    long long result = 0;
    for (int i = 0; i < 500'001; i++)
    {
        if (!sosu[i])
            continue;
        result += cnt[i];
    }
    cout << result * (nofPrice[0] + 1) << '\n';
}