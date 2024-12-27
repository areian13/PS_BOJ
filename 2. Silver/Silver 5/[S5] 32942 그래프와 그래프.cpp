#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 10

int main()
{
    FastIO;

    int a, b, c;
    cin >> a >> b >> c;

    for (int x = 1; x <= MAX; x++)
    {
        bool hasY = false;
        for (int y = 1; y <= MAX; y++)
        {
            if (a * x + b * y == c)
            {
                cout << y << ' ';
                hasY = true;
            }
        }
        if (!hasY)
            cout << 0 << ' ';
        cout << '\n';
    }
}