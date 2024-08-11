#include <iostream>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string k;
        cin >> k;

        int n = k.size();

        vector<vector<char>> result(n, vector<char>(n, ' '));
        for (int i = 0; i < n; i++)
        {
            result[0][i] = k[i];
            result[n - 1][n - 1 - i] = k[i];
            result[i][0] = k[i];
            result[n - 1 - i][n - 1] = k[i];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << result[i][j];
            cout << '\n';
        }
    }
}