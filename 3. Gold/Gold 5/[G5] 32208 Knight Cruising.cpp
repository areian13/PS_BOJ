#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        long long x, y, z;
        cin >> x >> y >> z;

        long long add = x + y + z;
        bool result = ~add & 1;
        cout << (result ? "YES" : "NO") << '\n';
    }
}