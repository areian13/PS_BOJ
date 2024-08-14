#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define WEEK_SEC (60 * 60 * 24 * 7)

long long Factorial(long long n)
{
    if (n <= 1)
        return 1;
    return n * Factorial(n - 1);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    long long nWeekSec = Factorial(n);
    int result = nWeekSec / WEEK_SEC;
    cout << result << '\n';
}