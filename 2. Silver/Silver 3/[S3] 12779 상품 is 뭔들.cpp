#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long GCD(long long a, long long b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

long long sqrt(long long n)
{
    if (n == 0)
        return 0;

    long long start = 1;
    long long end = n;
    long long result = 1;
    while (start <= end)
    {
        long long mid = (start + end) / 2;

        if (mid == n / mid)
            return mid;

        if (mid < n / mid)
        {
            start = mid + 1;
            result = mid;
        }
        else
            end = mid - 1;
    }
    return result;
}

int main()
{
    FastIO;

    long long a, b;
    cin >> a >> b;

    long long p = sqrt(b) - sqrt(a);
    long long q = b - a;

    long long gcd = GCD(p, q);
    p /= gcd;
    q /= gcd;

    if (p == 0)
        printf("0\n");
    else
        printf("%lld/%lld\n", p, q);
}