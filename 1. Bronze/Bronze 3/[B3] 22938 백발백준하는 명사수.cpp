#include <iostream>
#include <cmath>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double dx = abs(x1 - x2);
    double dy = abs(y1 - y2);

    double dist = sqrt(dx * dx + dy * dy);
    string result = (dist < r1 + r2 ? "YES" : "NO");
    cout << result << '\n';
}