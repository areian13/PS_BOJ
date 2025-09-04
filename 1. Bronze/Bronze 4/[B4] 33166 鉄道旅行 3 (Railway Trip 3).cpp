#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int p, q, a, b;
    cin >> p >> q >> a >> b;

    int result = min(p, q) * a + max(q - p, 0) * b;
    cout << result << '\n';
}