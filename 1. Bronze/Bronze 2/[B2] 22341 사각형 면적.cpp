#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, c;
    cin >> n >> c;

    int a = n, b = n;
    for (int i = 0; i < c; i++)
    {
        int x, y;
        cin >> x >> y;

        if (x >= a || y >= b)
            continue;

        int p = b * x;
        int q = a * y;

        if (p >= q)
            a = x;
        else
            b = y;
    }

    int result = a * b;
    cout << result << '\n';
}