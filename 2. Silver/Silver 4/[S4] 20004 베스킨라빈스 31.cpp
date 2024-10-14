#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a;
    cin >> a;

    for (int i = 1; i <= a; i++)
    {
        if (30 % (i + 1) == 0)
            cout << i << '\n';
    }
}