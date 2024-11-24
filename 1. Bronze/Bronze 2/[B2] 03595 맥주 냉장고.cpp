#include <iostream>
#include <array>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 3> MinSize(int n)
{
    int minSize = INT_MAX;
    array<int, 3> result = { INT_MAX,INT_MAX,INT_MAX };
    for (int x = 1; x <= n; x++)
    {
        if (n % x != 0)
            continue;

        int h = n / x;
        for (int y = 1; y <= h; y++)
        {
            if (h % y != 0)
                continue;

            int z = h / y;
            int temp = (x * y + y * z + z * x) * 2;
            if (temp < minSize)
            {
                result = { x,y,z };
                minSize = temp;
            }
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<int, 3> result = MinSize(n);
    cout << result[0] << ' ' << result[1] << ' ' << result[2] << '\n';
}