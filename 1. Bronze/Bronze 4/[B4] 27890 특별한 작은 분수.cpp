#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int x, n;
    cin >> x >> n;

    for (int i = 0; i < n; i++)
        x = (x % 2 == 0 ? (x / 2) ^ 6 : (2 * x) ^ 6);
    cout << x << '\n';
}