#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long GCD(long long a, long long b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int main()
{
    FastIO;

    long long n, a, b;
    cin >> n >> a >> b;

    if (GCD(a, b) > 1)
        cout << "No" << '\n';
    else
    {
        cout << "Yes" << '\n';
        for (int i = 0; i < n; i++)
        {
            long long result = a + 2 * i * b;
            cout << result << ' ' << result + b << '\n';
        }
    }
}