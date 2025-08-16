#include <iostream>
#include <vector>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, l;
    cin >> n >> l;

    vector<int> result;
    for (int i = l; i <= 100; i++)
    {
        int a = n / i - i / 2 + (n % i != 0);
        if (a < 0)
            continue;

        long long s = 1LL * i * (a * 2 + i - 1) / 2;

        if (s == n)
        {
            for (int j = a; j < a + i; j++)
                result.push_back(j);
            break;
        }
    }

    if (result.empty())
        cout << -1 << '\n';
    else
    {
        for (int v : result)
            cout << v << ' ';
        cout << '\n';
    }
}