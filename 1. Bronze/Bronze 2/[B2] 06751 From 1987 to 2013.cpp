#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsDistinct(int y)
{
    array<bool, 10> isCounted = { false, };
    do
    {
        if (isCounted[y % 10])
            return false;
        isCounted[y % 10] = true;
        y /= 10;
    } while (y > 0);
    return true;
}

int main()
{
    FastIO;

    int y;
    cin >> y;

    int result = y + 1;
    while (!IsDistinct(result))
        result++;
    cout << result << '\n';
}