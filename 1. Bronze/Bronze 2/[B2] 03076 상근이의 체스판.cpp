#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int r, c, a, b;
    cin >> r >> c >> a >> b;

    for (int i = 0; i < r * a; i++)
    {
        for (int j = 0; j < c * b; j++)
        {
            if ((i / a + j / b) % 2 == 0)
                cout << 'X';
            else
                cout << '.';
        }
        cout << '\n';
    }
}