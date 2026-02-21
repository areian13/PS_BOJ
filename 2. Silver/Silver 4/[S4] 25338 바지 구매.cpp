#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        result += (v >= b && max(a * (v - b) * (v - b) + c, d) == u);
    }
    cout << result << '\n';
}