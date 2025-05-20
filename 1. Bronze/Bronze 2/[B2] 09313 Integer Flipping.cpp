#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

unsigned int FlipBin(unsigned int n)
{
    unsigned int result = 0;
    for (int i = 0; i < 31; i++)
    {
        result += n & 1;
        n >>= 1;
        result <<= 1;
    }
    return result;
}

int main()
{
    FastIO;

    while (true)
    {
        long long n;
        cin >> n;

        if (n == -1)
            break;

        unsigned int result = FlipBin(n);
        cout << result << '\n';
    }
}