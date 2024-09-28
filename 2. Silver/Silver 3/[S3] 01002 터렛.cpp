#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountPos(int x1, int y1, int r1, int x2, int y2, int r2)
{
    double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    int rSum = r1 + r2;
    int rGap = abs(r1 - r2);

    if (dist == 0 && r1 == r2)
        return -1;
    if (dist < rGap || dist > rSum)
        return 0;
    if (dist == rGap || dist == rSum)
        return 1;
    return 2;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int result = CountPos(x1, y1, r1, x2, y2, r2);
        cout << result << '\n';
    }
}