#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int k;
    cin >> k;

    vector<int> d;
    d.push_back(1), d.push_back(-1);
    for (int i = 2; i * i <= abs(k); i++)
    {
        if (k % i == 0)
        {
            d.push_back(i), d.push_back(-i);
            if (i * i != abs(k))
                d.push_back(k / i), d.push_back(-k / i);
        }
    }
    if(abs(k) != 1)
    d.push_back(k), d.push_back(-k);

    vector<long long> result;
    for (int s : d)
    {
        long long b = k + k / s;
        long long a = (long long)s * b;

        result.push_back(a + b);
    }
    sort(result.begin(), result.end());

    cout << result.size() << ' ' << accumulate(result.begin(), result.end(), 0LL) << '\n';
}