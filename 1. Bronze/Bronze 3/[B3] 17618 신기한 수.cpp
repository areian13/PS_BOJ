#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsStrangeNum(int n)
{
    int m = n;
    int sum = 0;
    while (m > 0)
    {
        sum += m % 10;
        m /= 10;
    }
    return (n % sum == 0);
}

int CountStrangeNum(int n)
{
    int result = 0;
    for (int i = 1; i <= n; i++)
        result += IsStrangeNum(i);
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = CountStrangeNum(n);
    cout << result << '\n';
}