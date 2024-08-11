#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    double n, t, m, x, y;
    cin >> n >> t >> m >> x >> y;

    double time = (m / x + (n - m) / y) / 60 - t;
    int result = (time <= 0 ? 0 : ceil(time));
    cout << result << '\n';
}