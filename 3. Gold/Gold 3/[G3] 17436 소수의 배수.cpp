#include <iostream>
#include <vector>
#include <numeric>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    long long m;
    cin >> n >> m;

    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    long long result = 0;
    for (int i = 1; i < 1 << n; i++)
    {
        long long l = 1;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                l *= p[j];
        }

        result += m / l * (popcount(1u * i) & 1 ? +1 : -1);
    }
    cout << result << '\n';
}