#include <iostream>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();
    char ai, bi;
    for (int i = 0; a[i] != '\0'; i++)
    {
        int bt = b.find(a[i]);
        if (bt != -1)
        {
            ai = i, bi = bt;
            break;
        }
    }

    vector<vector<char>> result(m, vector<char>(n, '.'));
    for (int i = 0; i < m; i++)
        result[i][ai] = b[i];
    for (int i = 0; i < n; i++)
        result[bi][i] = a[i];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << result[i][j];
        cout << '\n';
    }
}