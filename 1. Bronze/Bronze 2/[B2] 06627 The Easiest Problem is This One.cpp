#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int S(int n)
{
    int s = 0;
    while (n > 0)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int MinP(int n)
{
    int sn = S(n);
    int p = 11;
    while (S(n * p) != sn)
        p++;
    return p;
}

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        int result = MinP(n);
        cout << result << '\n';
    }
}