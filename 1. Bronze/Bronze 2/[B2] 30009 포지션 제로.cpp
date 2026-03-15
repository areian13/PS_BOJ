#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, x, y, r;
    cin >> n >> x >> y >> r;

    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;

        if (x - r < t && t < x + r) a++;
        else if (x - r == t || t == x + r) b++;
    }

    cout << a << ' ' << b << '\n';
}