#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 2> xy;
    cin >> xy[0] >> xy[1];

    long long result = 0;
    for (int i = 0; i < 16; i++)
    {
        for (int j = 1; j >= 0; j--)
            result |= (xy[j] & (1 << i)) << (i + !j);
    }
    cout << result << '\n';
}