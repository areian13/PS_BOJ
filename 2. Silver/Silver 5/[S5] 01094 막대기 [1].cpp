#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Count1Bit(int x)
{
    int result = 0;
    while (x > 0)
    {
        result += x & 1;
        x >>= 1;
    }
    return result;
}

int main()
{
    FastIO;

    int x;
    cin >> x;

    int result = Count1Bit(x);
    cout << result << '\n';
}