#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Pow(int a, int b, int c)
{
    if (b == 1)
        return a % c;

    long long result = Pow(a, b / 2, c);
    result *= result;
    result %= c;

    if (b % 2 == 1)
    {
        result *= a;
        result %= c;
    }

    return result;
}

int main()
{
    FastIO;

    int a, b, c;
    cin >> a >> b >> c;

    int result = Pow(a, b, c);
    cout << result << '\n';
}