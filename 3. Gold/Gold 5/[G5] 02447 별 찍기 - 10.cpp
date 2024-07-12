#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsStar(int y, int x, int n)
{
    if ((y / n) % 3 == 1 && (x / n) % 3 == 1)
        return false;
    if (n == 1)
        return true;
    return IsStar(y, x, n / 3);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char result = IsStar(i, j, n) ? '*' : ' ';
            cout << result;
        }
        cout << '\n';
    }
}