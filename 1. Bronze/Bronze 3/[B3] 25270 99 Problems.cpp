#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Nearest99(int n)
{
    if (n <= 99)
        return 99;

    int M = (n / 100) * 100 + 99;
    int m = (n / 100) * 100 - 1;

    return (M - n <= n - m ? M : m);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = Nearest99(n);
    cout << result << '\n';
}