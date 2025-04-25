#include <iostream>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        long long k;
        cin >> k;

        long long v = bit_ceil((unsigned long long)k);
        int result = 0;
        while (k > 0)
        {
            if (k >= v)
                k -= v;
            v /= 2;
            result += (k != 0);
        }
        cout << result << '\n';
    }
}