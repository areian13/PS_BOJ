#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, a, b;
    cin >> n >> a >> b;

    array<int, 4> result = { 0, };
    for (int i = 1; i <= n; i++)
        result[(i % a == 0) * 1 + (i % b == 0) * 2]++;

    for (int i = 1; i <= 3; i++)
        cout << result[i] << ' ';
    cout << '\n';
}