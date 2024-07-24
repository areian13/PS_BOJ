#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void MakeStar(int s, int r, int c, vector<vector<char>>& map)
{
    if (r <= 0 || c <= 0)
        return;

    for (int i = s; i < s + c; i++)
    {
        map[s][i] = '*';
        map[s + r - 1][i] = '*';
    }
    for (int i = s; i < s + r; i++)
        map[i][s] = '*';
    for (int i = s + 2; i < s + r; i++)
        map[i][s + c - 1] = '*';
    if (c != 1)
        map[s + 2][s + c - 2] = '*';

    MakeStar(s + 2, r - 4, c - 4, map);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int r = (n == 1 ? 1 : (n - 1) * 4 + 3);
    int c = (n - 1) * 4 + 1;

    vector<vector<char>> result(r, vector<char>(c, ' '));
    MakeStar(0, r, c, result);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 1 && j > 0)
                break;
            cout << result[i][j];
        }
        cout << '\n';
    }
}