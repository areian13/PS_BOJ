#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    array<int, 2> result = { max(n - m * k, 0),n - m * (k - 1) - 1 };
    cout << result[0] << ' ' << result[1] << '\n';
}