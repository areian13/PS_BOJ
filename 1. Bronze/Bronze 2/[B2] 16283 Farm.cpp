#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 2> SG(int a, int b, int n, int w)
{
    array<int, 2> result = { -1,-1 };
    for (int i = 1; i < n; i++)
    {
        if (a * i + (n - i) * b == w)
        {
            if (result[0] != -1)
                return { -1,-1 };
            result = { i,n - i };
        }
    }
    return result;
}

int main()
{
    FastIO;

    int a, b, n, w;
    cin >> a >> b >> n >> w;

    array<int, 2> result = SG(a, b, n, w);
    if (result[0] == -1)
        cout << -1 << '\n';
    else
        cout << result[0] << ' ' << result[1] << '\n';
}