#include <iostream>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;


    int y = 1;
    int minY = INT_MAX;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;

        if (a < minY)
        {
            minY = a;
            y = i + 1;
        }
    }

    int x = 1;
    int minX = a;
    for (int i = 0; i < m - 1; i++)
    {
        cin >> a;

        if (a < minX)
        {
            minX = a;
            x = i + 2;
        }
    }
    cout << y << ' ' << x << '\n';
}