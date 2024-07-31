#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    int result = n * (m >= k ? m / k + k - 1 : m);
    cout << result << '\n';
}