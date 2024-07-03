#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long a, b, c;
    cin >> a >> b >> c;

    long long n = a * b;
    string result = to_string(n / c) + '.';
    for (int i = 0; i < 6; i++)
    {
        n %= c;
        n *= 10;

        result += (n / c + '0');
    }
    cout << result << '\n';
}