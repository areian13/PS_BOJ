#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int p = 1, q = 1;
    for (int i = 1; i < n; i++)
    {
        if (p == 1)
        {
            p = q + 1;
            q = 1;
        }
        else
            p--, q++;
    }
    cout << p << ' ' << q << '\n';
}