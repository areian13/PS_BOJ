#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, x, k;
    cin >> n >> x >> k;

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;

        if (a == x)
            x = b;
        else if (b == x)
            x = a;
    }
    cout << x << '\n';
}