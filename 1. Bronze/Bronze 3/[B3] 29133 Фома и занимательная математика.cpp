#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int X(int a, int b, int c, int d)
{
    int cnt = 0;
    int result = -1;
    for (int x = 1; x <= 3; x++)
    {
        if (pow(a, x) + pow(b, x) + pow(c, x) == d)
        {
            cnt++;
            result = x;
        }
    }
    return cnt == 1 ? result : -1;
}

int main()
{
    FastIO;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int result = X(a, b, c, d);
    cout << result << '\n';
}