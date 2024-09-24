#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n, m, c;
        cin >> n >> m >> c;

        if (n == 0 && m == 0 && c == 0)
            break;

        int result = ((n - 7) * (m - 7) + (c == 1)) / 2;
        cout << result << '\n';
    }
}