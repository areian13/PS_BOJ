#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long a, b;
    cin >> a >> b;

    if (a > b)
        swap(a, b);

    int cnt = max(b - a - 1, 0ll);
    cout << cnt << '\n';
    for (long long i = a + 1; i < b; i++)
        cout << i << ' ';
}