#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsConstructor(int c, int n)
{
    int sum = c;
    while (c > 0)
    {
        sum += c % 10;
        c /= 10;
    }
    return sum == n;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    while (!IsConstructor(result, n) && result <= n)
        result++;
    result = (result != n + 1 ? result : 0);
    cout << result << '\n';
}