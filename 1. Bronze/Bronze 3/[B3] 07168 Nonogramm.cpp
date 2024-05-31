#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    vector<vector<int>> cntRow(n);
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == '#')
                cnt++;
            else if (cnt != 0)
            {
                cntRow[i].push_back(cnt);
                cnt = 0;
            }
        }
        if (cntRow[i].empty() || cnt != 0)
            cntRow[i].push_back(cnt);
    }

    for (int i = 0; i < n; i++)
    {
        for (int x : cntRow[i])
            cout << x << ' ';
        cout << '\n';
    }

    vector<vector<int>> cntCol(m);
    for (int j = 0; j < m; j++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (map[i][j] == '#')
                cnt++;
            else if (cnt != 0)
            {
                cntCol[j].push_back(cnt);
                cnt = 0;
            }
        }
        if (cntCol[j].empty() || cnt != 0)
            cntCol[j].push_back(cnt);
    }

    for (int j = 0; j < m; j++)
    {
        for (int x : cntCol[j])
            cout << x << ' ';
        cout << '\n';
    }
}