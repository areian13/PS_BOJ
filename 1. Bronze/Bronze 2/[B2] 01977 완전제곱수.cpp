#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b;
    cin >> a >> b;

    int sum = 0, min = -1;
    for (int i = 1; i * i <= b; i++)
    {
        if (i * i >= a)
        {
            sum += i * i;
            min = min == -1 ? i * i : min;
        }
    }

    if (min == -1)
        cout << -1 << '\n';
    else
        cout << sum << '\n' << min << '\n';
}