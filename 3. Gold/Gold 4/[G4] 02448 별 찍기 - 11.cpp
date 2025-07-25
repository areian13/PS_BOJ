#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<vector<char>> star;
array<array<char, 6>, 3> tri =
{
    "  *  ",
    " * * ",
    "*****",
};

void Star(int y, int x, int n)
{
    if (n == 1)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 5; j++)
                star[y + i][x + j] = tri[i][j];
        }
        return;
    }
    Star(y, x + 3 * n / 2, n / 2);
    Star(y + 3 * n / 2, x, n / 2);
    Star(y + 3 * n / 2, x + 3 * n, n / 2);
}
int main()
{
    FastIO;

    int n;
    cin >> n;

    star.resize(n, vector<char>(2 * n, ' '));
    Star(0, 0, n / 3);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 2; j++)
            cout << star[i][j];
        cout << '\n';
    }
}