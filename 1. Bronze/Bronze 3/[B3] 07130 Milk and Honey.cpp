#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int m, h, n;
    cin >> m >> h >> n;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int c, b;
        cin >> c >> b;

        result += max(c * m, b * h);
    }
    cout << result << '\n';
}