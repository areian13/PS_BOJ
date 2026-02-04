#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }

    int result = 0;
    for (int i = 0; i < m - 1; i++)
        result += grid[a[i]][a[i + 1]];
    cout << result << '\n';
}