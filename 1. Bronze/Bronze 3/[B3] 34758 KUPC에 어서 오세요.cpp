#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int ox, oy, n;
    cin >> ox >> oy >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        int result = (x != ox && y != oy);
        cout << result << '\n';
    }
}