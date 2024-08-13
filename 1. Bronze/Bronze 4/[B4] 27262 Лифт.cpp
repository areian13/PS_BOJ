#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k, a, b;
    cin >> n >> k >> a >> b;

    array<int, 2> result = { (n + k - 2) * b,(n - 1) * a };
    cout << result[0] << ' ' << result[1] << '\n';
}