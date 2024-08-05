#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int result = (n > 1 ? min(a, b) + (n - 2) * min({ a,b,c }) : 0);
    cout << result / 100 << ' ' << result % 100 << '\n';
}