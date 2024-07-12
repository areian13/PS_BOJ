#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m, a;
    cin >> n >> m >> a;

    vector<vector<int>> noise(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> noise[i][j];
    }

    int result = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
            result += a * (noise[i + 1][j] > 2 * noise[i][j]);
    }
    cout << result << '\n';
}