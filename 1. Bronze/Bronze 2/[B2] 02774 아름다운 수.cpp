#include <iostream>
#include <array>
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
        int x;
        cin >> x;

        array<bool, 10> d = { false, };
        do
        {
            d[x % 10] = true;
            x /= 10;
        } while (x > 0);

        int result = accumulate(d.begin(), d.end(), 0);
        cout << result << '\n';
    }
}