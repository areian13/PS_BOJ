#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Fly(int x, int y, int c)
{
    double distSqr = sqrt(x * x + y * y);
    if ((int)distSqr == distSqr && (int)distSqr % c == 0)
        return (int)distSqr / c;
    return distSqr / c + (distSqr < c) + 1;
}

int main()
{
    FastIO;

    int x, y, c;
    cin >> x >> y >> c;

    int result = Fly(x, y, c);
    cout << result << '\n';
}