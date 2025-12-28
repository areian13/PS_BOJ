#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<vector<bool>> isPalin(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
        isPalin[i][i] = true;
    for (int l = 2; l <= n; l++)
    {
        for (int i = 0, j = i + l - 1; j < n; i++, j++)
            isPalin[i][j] = (a[i] == a[j] && (l == 2 || isPalin[i + 1][j - 1]));
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        s--, e--;

        cout << isPalin[s][e] << '\n';
    }
}