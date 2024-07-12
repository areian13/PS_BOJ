#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int x = n % 3;

    int a = (x + 1) / 2 * (3 - x);
    int b = n / 3 - (x == 1);

    cout << a << ' ' << b << '\n';
}
