#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<char>> stop(n, vector<char>(n, ' '));
    for (int i = 0; i < n; i++)
    {
        stop[i][0] = stop[0][i] = stop[n - 1][i] = stop[i][n - 1] = '*';
        stop[i][i] = stop[n - 1 - i][i] = '*';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << stop[i][j];
        cout << '\n';
    }
}