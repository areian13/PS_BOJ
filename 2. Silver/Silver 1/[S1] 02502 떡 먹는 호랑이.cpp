#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int d, k;
    cin >> d >> k;

    vector<int> fib(d + 1);
    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i <= d; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    int a = 1, b = -1;
    while (true)
    {
        int r = k - a * fib[d - 2];
        if (r % fib[d - 1] == 0 && r / fib[d - 1] >= a)
        {
            b = r / fib[d - 1];
            break;
        }
        a++;
    }
    cout << a << '\n' << b << '\n';
}