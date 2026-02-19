#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int DigitSum(int n, int d)
{
    int result = 0;
    while (n > 0)
    {
        result += n % d;
        n /= d;
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    pair<int, int> result = { 0,-1 };
    for (int i = 2; i <= n; i++)
    {
        int value = DigitSum(n, i);
        if (value > result.first)
            result = { value, i };
    }

    cout << result.first << ' ' << result.second << '\n';
}