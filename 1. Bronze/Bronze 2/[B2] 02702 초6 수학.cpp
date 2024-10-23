#include <iostream>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int a, b;
        cin >> a >> b;

        int l = lcm(a, b);
        int g = gcd(a, b);

        cout << l << ' ' << g << '\n';
    }
}