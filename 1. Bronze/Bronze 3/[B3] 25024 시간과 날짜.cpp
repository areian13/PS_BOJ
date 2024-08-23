#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanTime(int x, int y)
{
    return (0 <= x && x <= 23) && (0 <= y && y <= 59);
}

bool CanDate(int x, int y)
{
    if (!(1 <= x && x <= 12))
        return false;
    if (x == 2)
        return (1 <= y && y <= 29);

    if (x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12)
        return (1 <= y && y <= 31);
    return (1 <= y && y <= 30);
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int x, y;
        cin >> x >> y;

        array<string, 2> result = { "No","Yes" };
        cout << result[CanTime(x, y)] << ' ' << result[CanDate(x, y)] << '\n';
    }
}