#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 2024 * 12 + 7 + (n - 1) * 7;
    cout << result / 12 << ' ' << result % 12 + 1 << '\n';
}