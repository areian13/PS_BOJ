#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int DigitCount(int num, int d)
{
    int result = 0;
    while (num > 0)
    {
        result += (num % 10 == d);
        num /= 10;
    }
    return result;
}

int main()
{
    FastIO;

    int s, e, n;
    cin >> s >> e >> n;

    int result = 0;
    for (int i = s; i <= e; i++)
        result += DigitCount(i, n);
    cout << result << '\n';
}