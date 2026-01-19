#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, p;
    cin >> n >> p;

    long long result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
        result %= p;
    }
    cout << result << '\n';
}