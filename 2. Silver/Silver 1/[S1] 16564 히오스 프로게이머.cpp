#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long Level(int t, vector<int>& x)
{
    long long result = 0;
    for (int l : x)
        result += max(t - l, 0);
    return result;
}

int MaxT(int k, vector<int>& x)
{
    int s = 1, e = 2e+9;
    int result = s;
    while (s <= e)
    {
        int m = (1LL * s + e) / 2;
        if (Level(m, x) <= k)
        {
            s = m + 1;
            result = m;
        }
        else
            e = m - 1;
    }
    return result;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    int result = MaxT(k, x);
    cout << result << '\n';
}