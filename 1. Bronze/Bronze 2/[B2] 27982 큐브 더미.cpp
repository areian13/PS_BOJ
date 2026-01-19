#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector cube(n, vector(n, vector(n, false)));
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--, z--;
        cube[x][y][z] = true;
    }

    int result = 0;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            for (int k = 1; k < n - 1; k++)
            {
                if (!cube[i][j][k]) continue;
                if (!cube[i - 1][j][k]) continue;
                if (!cube[i + 1][j][k]) continue;
                if (!cube[i][j - 1][k]) continue;
                if (!cube[i][j + 1][k]) continue;
                if (!cube[i][j][k - 1]) continue;
                if (!cube[i][j][k + 1]) continue;
                result++;

            }
        }
    }
    cout << result << '\n';
}