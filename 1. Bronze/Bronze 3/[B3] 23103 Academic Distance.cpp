#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;


int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    int px, py;
    cin >> px >> py;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;

        result += abs(px - x) + abs(py - y);
        px = x;
        py = y;
    }
    cout << result << '\n';
}