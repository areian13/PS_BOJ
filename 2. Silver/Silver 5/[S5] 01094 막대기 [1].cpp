#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int BitCount(int x)
{
    int result = 0;
    while (x > 0)
    {
        result += (x % 2);
        x >>= 1;
    }
    return result;
}

int main()
{
    FastIO;

    int x;
    cin >> x;

    int result = BitCount(x);
    cout << result << '\n';
}