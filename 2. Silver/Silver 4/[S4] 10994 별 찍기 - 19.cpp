#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void MakeStar(int p, int k, vector<vector<char>>& result)
{
    if (k <= 0)
        return;

    for (int i = p; i < p + k; i++)
    {
        result[i][p] = '*';           // аб
        result[i][p + k - 1] = '*';   // ©Л
        result[p][i] = '*';           // ╩С
        result[p + k - 1][i] = '*';   // го
    }

    MakeStar(p + 2, k - 4, result);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int k = (n - 1) * 4 + 1;
    
    vector<vector<char>> result(k, vector<char>(k, ' '));
    MakeStar(0, k, result);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
            cout << result[i][j];
        cout << '\n';
    }
}