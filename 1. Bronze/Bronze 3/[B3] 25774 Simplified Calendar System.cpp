#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Day(int y, int m, int d)
{
    return (y - 1) * 12 * 30 + (m - 1) * 30 + d;
}

int main()
{
    FastIO;

    int d1, m1, y1, n, d2, m2, y2;
    cin >> d1 >> m1 >> y1 >> n >> d2 >> m2 >> y2;

    int day = Day(y2, m2, d2) - Day(y1, m1, d1);
    int result = (day + n - 1) % 7 + 1;
    cout << result << '\n';
}
