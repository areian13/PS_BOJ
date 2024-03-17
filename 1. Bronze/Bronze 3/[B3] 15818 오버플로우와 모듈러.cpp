#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    long long result = 1;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;

        result *= (a % m);
        result %= m;
    }
    cout << result << '\n';
}