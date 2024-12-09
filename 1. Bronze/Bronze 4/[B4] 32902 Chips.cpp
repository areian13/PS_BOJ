#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int k, n;
    cin >> k >> n;

    cout << n + 1 << ' ' << k * n + 1 << '\n';
}