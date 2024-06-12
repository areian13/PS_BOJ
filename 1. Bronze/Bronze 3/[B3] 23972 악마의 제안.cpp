#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long k, n;
    cin >> k >> n;

    int result = n == 1 ? -1 : (k * n / (n - 1)) + (k * n % (n - 1) != 0);
    cout << result << '\n';
}