#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Bill(int x, int y)
{
    if (x + y == 13)
        return "Never speak again.";
    if (x > y)
        return "To the convention.";
    if (x < y)
        return "Left beehind.";
    return "Undecided.";
}

int main()
{
    FastIO;

    while (true)
    {
        int x, y;
        cin >> x >> y;

        if (x == 0 && y == 0)
            break;

        string result = Bill(x, y);
        cout << result << '\n';
    }
}