#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 8

int Repaint(int i, int j, vector<vector<char>>& chess)
{
    int result = 0;
    for (int k = i; k < i + MAX; k++)
    {
        for (int l = j; l < j + MAX; l++)
            result += (chess[k][l] == ((k + l) % 2 == 0 ? 'W' : 'B'));
    }
    result = min(result, MAX * MAX - result);
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> chess(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> chess[i][j];
    }

    int result = MAX * MAX;
    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j++)
            result = min(result, Repaint(i, j, chess));
    }
    cout << result << '\n';
}