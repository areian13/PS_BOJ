#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

typedef unsigned long long ull;

int main()
{
    FastIO;

    ull n;
    cin >> n;

    ull nofFace = (n - 2) * (5 * n - 6);
    ull nofEdge = 8 * n - 12;
    ull nofVertex = 4;

    ull a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    if (n == 1)
    {
        cout << a + b + c + d + e + f - max({ a,b,c,d,e,f });
        return 0;
    }
    ull face = min({ a,b,c,d,e,f });
    ull edge = min({
        a + b,a + c,a + d,a + e,
        f + b,f + c,f + d,f + e,
        d + e,e + c,c + b,b + d
        });
    ull vertex = min({
        a + b + c,a + c + e,a + e + d,a + d + b,
        f + b + c,f + c + e,f + e + d,f + d + b,
        });

    ull result = nofFace * face + nofEdge * edge + nofVertex * vertex;
    cout << result << '\n';
}