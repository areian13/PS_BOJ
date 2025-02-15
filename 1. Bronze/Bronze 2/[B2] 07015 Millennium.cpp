#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Day(int y, int m, int d)
{
    int result = 0;
    for (int i = 1; i < y; i++)
        result += (i % 3 == 0 ? 200 : 195);
    for (int i = 1; i < m; i++)
        result += (y % 3 == 0 || i % 2 == 1 ? 20 : 19);
    result += d;
    return result;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int i = 1; i <= TC; i++)
    {
        int y, m, d;
        cin >> y >> m >> d;

        int result = Day(1'000, 1, 1) - Day(y, m, d);
        cout << result << '\n';
    }
}