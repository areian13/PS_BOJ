#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 2> FindAC(int m, int s, int x1, int x2)
{
    for (int a = 0; a < m; a++)
    {
        for (int c = 0; c < m; c++)
        {
            if ((a * s + c) % m == x1 && (a * x1 + c) % m == x2)
                return { a,c };
        }
    }
    return { -1,-1 };
}

int main()
{
    FastIO;

    int m, s, x1, x2;
    cin >> m >> s >> x1 >> x2;

    array<int, 2> result = FindAC(m, s, x1, x2);
    cout << result[0] << ' ' << result[1] << '\n';
}