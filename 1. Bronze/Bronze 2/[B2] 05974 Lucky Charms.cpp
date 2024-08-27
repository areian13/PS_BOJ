#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int l, c, n;
    cin >> l >> c >> n;

    for (int i = 0; i < c; i++)
    {
        int s, p;
        cin >> s >> p;

        int result = abs(n - p) + s;
        cout << result << '\n';
    }
}