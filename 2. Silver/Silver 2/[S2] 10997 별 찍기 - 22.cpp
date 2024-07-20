#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void MakeStar(int p, int k, int s, vector<vector<char>>& result)
{
    if (k <= 0 || s <= 0)
        return;

    for (int i = p; i < p + s; i++)
    {
        result[p][i] = '*';
        result[p + k - 1][i] = '*';
    }
    for (int i = p; i < p + k; i++)
        result[i][p] = '*';
    for (int i = p + 2; i < p + k; i++)
        result[i][p + s - 1] = '*';

    if (s != 1)
        result[p + 2][p + s - 2] = '*';

    MakeStar(p + 2, k - 4, s - 4, result);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int k = n == 1 ? 1 : (n - 1) * 4 + 3;
    int s = (n - 1) * 4 + 1;

    vector<vector<char>> result(k, vector<char>(s, ' '));
    MakeStar(0, k, s, result);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (i == 1 && j > 0)
                continue;

            cout << result[i][j];
        }
        cout << '\n';
    }
}