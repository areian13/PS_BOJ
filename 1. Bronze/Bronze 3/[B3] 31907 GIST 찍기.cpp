#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

char GIST(int y, int x)
{

    if (y == 0 && x == 0)
        return 'G';
    if (y == 1 && x == 1)
        return 'I';
    if (y == 2 && x == 2)
        return 'S';
    if (y == 1 && x == 3)
        return 'T';
    return '.';
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    for (int i = 0; i < n * 3; i++)
    {
        for (int j = 0; j < n * 4; j++)
            cout << GIST(i / n, j / n);
        cout << '\n';
    }
}