#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Section(double x, double y)
{
    if (x > 0 && y > 0)
        return "Q1";
    if (x < 0 && y > 0)
        return "Q2";
    if (x < 0 && y < 0)
        return "Q3";
    if (x > 0 && y < 0)
        return "Q4";
    return "AXIS";
}

int main()
{
    FastIO;

    while (true)
    {
        double x, y;
        cin >> x >> y;

        string result = Section(x, y);
        cout << result << '\n';

        if (x == 0 && y == 0)
            break;
    }
}