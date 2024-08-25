#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int x, n;
    cin >> x >> n;

    int result = 0;
    while (x < n)
    {
        result++;

        int r = x % 3;
        if (r == 0)
            x++;
        else if (r == 1)
            x *= 2;
        else if (r == 2)
            x *= 3;
    }
    cout << result << '\n';
}