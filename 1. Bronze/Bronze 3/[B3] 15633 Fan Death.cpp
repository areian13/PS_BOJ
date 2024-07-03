#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            result += i;
    }
    result = 5 * result - 24;

    cout << result << '\n';
}