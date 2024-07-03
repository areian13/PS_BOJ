#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int k, n;
    cin >> k >> n;

    for (int i = 1; i < n; i++)
        cout << i << '\n';

    int result = k - n * (n - 1) / 2;
    cout << result << '\n';
}