#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int MinGame(int x, int y)
{
    int z = y * 100LL / x;
    if (z >= 99)
        return -1;

    int start = 0, end = 1'000'000'000;
    int result = end;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int tempZ = (y + mid) * 100LL / (x + mid);
        if (z >= tempZ)
            start = mid + 1;
        else
        {
            result = min(result, mid);
            end = mid - 1;
        }
    }
    return result;
}

int main(void)
{
    FastIO;

    int x, y;
    cin >> x >> y;

    int result = MinGame(x, y);
    cout << result << '\n';
}