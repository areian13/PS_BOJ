#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    vector<int> d(n - 1);
    int dist = 0;
    for (int i = 0; i < n - 1; i++)
    {
        d[i] = x[i + 1] - x[i];
        dist = GCD(dist, d[i]);
    }

    int result = 0;
    for (int i = 0; i < n - 1; i++)
        result += (d[i] / dist - 1);
    cout << result << '\n';
}