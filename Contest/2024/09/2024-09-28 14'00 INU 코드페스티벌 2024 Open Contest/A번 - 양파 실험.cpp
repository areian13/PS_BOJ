#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, a, b;
    cin >> n >> a >> b;

    int p = 1, c = 1;
    for (int i = 0; i < n; i++)
    {
        p += a;
        c += b;

        if (p < c)
            swap(p, c);
        else if (p == c)
            c--;
    }
    cout << p << ' ' << c << '\n';
}