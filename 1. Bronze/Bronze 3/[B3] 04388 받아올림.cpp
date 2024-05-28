#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountCarry(long long a, long long b)
{
    int result = 0;
    bool carry = false;
    while (a > 0 || b > 0)
    {
        int l = a % 10;
        int r = b % 10;

        if (l + r + carry >= 10)
        {
            result++;
            carry = true;
        }
        else
            carry = false;

        a /= 10;
        b /= 10;
    }
    return result;
}

int main()
{
    FastIO;

    while (true)
    {
        long long a, b;
        cin >> a >> b;

        if (a == 0 && b == 0)
            break;

        int result = CountCarry(a, b);
        cout << result << '\n';
    }
}