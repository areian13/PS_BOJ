#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    int as = 0, bs = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        if (as + b >= k || bs + a >= k)
        {
            if (as + b >= k && bs + a >= k) result = +1;
            else if (as + b >= k) result = -1;
            else result = +1;
            break;
        }

        if (bs + a >= k || bs + a - (as + b) >= 50)
        {
            result = +1;
            break;
        }
        int op = a * 1.5;
        if (bs + op >= k || bs + op - (as + b) >= 50)
        {
            result = +1;
            break;
        }

        as += b, bs += a;
    }
    cout << result << '\n';
}