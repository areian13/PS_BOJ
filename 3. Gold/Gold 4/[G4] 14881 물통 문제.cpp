#include <iostream>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int i = 1; i <= TC; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        bool result = ((a >= c || b >= c) && c % gcd(a, b) == 0);
        if (result == true)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}