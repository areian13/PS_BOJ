#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 20> c;
    for (int i = 0; i < 20; i++)
        c[i] = i + 1;

    for (int i = 0; i < 10; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        reverse(c.begin() + a, c.begin() + b + 1);
    }

    for (int i = 0; i < 20; i++)
        cout << c[i] << ' ';
    cout << '\n';
}