#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 8> dy = { 1,1,1,0,-1,-1,-1,0 };
array<int, 8> dx = { -1,0,1,1,1,0,-1,-1 };

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<char>> field(n, vector<char>(n));
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> field[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (field[i][j] == '.')
                continue;
            for (int k = 0; k < 8; k++)
            {
                int ny = i + dy[k];
                int nx = j + dx[k];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                    continue;
                if (field[ny][nx] != '.')
                    continue;
                result[ny][nx] += (field[i][j] - '0');
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (field[i][j] != '.')
                cout << '*';
            else if (result[i][j] >= 10)
                cout << 'M';
            else
                cout << result[i][j];
        }
        cout << '\n';
    }
}