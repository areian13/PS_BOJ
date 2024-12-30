#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void GetDivisors(vector<int>& a, vector<int>& divisors)
{
    int g = 0;
    for (int x : a)
        g = gcd(g, x);

    for (int i = 1; i * i <= g; i++)
    {
        if (g % i == 0)
        {
            divisors.push_back(i);

            if (i * i != g)
                divisors.push_back(g / i);
        }
    }
    sort(divisors.begin(), divisors.end());
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> result;
    GetDivisors(a, result);

    for (int x : result)
        cout << x << '\n';
}