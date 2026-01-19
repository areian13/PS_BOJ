#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    for (int i = 0; i < n / 2 * 2; i++)
        cout << (i & 1 ? 2 : 1) << ' ';
    if (n & 1)
        cout << 3 << ' ';
    cout << '\n';
}