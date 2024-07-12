#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long MaxMoney(vector<int>& x)
{
    int n = x.size();
    sort(x.begin(), x.end());

    long long result = 0;
    int k = n / 4;
    for (int i = 0; i < k; i++)
    {
        for (int j = i; j < n; j += k)
            result += abs(x[j] - x[(j + k + n) % n]);
    }
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int n;
        cin >> n;

        vector<int> x(n);
        for (int i = 0; i < n; i++)
            cin >> x[i];

        long long result = MaxMoney(x);
        cout << "Case #" << t << endl;
        cout << result << endl;
    }
}