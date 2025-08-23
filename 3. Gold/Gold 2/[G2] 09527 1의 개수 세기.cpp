#include <iostream>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long SigBit(long long n)
{
    int d = bit_width((unsigned long long)n);
    n++;

    long long result = 0;
    for (int i = 0; i < d; i++)
        result += (n >> i + 1) * (1LL << i) + (((n >> i) & 1) & (n % (1LL << i)));
    return result;
}

int main()
{
    FastIO;

    long long a, b;
    cin >> a >> b;

    long long result = SigBit(b) - SigBit(a - 1);
    cout << result << '\n';
}