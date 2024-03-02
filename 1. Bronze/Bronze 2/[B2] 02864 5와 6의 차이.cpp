#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Change5And6(int n, bool make5)
{
    int result = n;
    int d = 1;
    while (n > 0)
    {
        if (n % 10 == 5 + make5)
            result += (make5 ? -1 : +1) * d;

        d *= 10;
        n /= 10;
    }
    return result;
}

int main()
{
    FastIO;

    int a, b;
    cin >> a >> b;

    int m = Change5And6(a, true) + Change5And6(b, true);
    int M = Change5And6(a, false) + Change5And6(b, false);

    cout << m << ' ' << M << '\n';
}