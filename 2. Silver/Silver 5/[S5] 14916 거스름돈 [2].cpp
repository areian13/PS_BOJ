#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MinCoin(int n)
{
    if (n == 1 || n == 3)
        return -1;

    if (n % 5 % 2 == 0)
        return (n / 5) + (n % 5 / 2);

    int n5 = (n - 5) / 5;
    return n5 + (n - n5 * 5) / 2;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = MinCoin(n);
    cout << result << '\n';
}