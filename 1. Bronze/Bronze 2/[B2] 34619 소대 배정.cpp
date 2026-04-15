#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, n, k;
    cin >> a >> b >> n >> k;

    int i = (k - 1) / n / b;
    int j = (k - 1) / n % b;
    cout << i + 1 << ' ' << j + 1 << '\n';
}