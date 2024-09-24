#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define PI 3.14159265359

int main()
{
    FastIO;

    while (true)
    {
        double x, y;
        cin >> x >> y;

        if (x == 0 && y == 0)
            break;

        int result = PI * (x * x + y * y) / 100 + 1;
        printf("The property will be flooded in hour %d.\n", result);
    }
}