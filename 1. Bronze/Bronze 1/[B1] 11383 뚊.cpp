#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsEyfa(vector<vector<char>>& a, vector<vector<char>>& b)
{
    int n = a.size();
    int m = a[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != b[i][j * 2] || a[i][j] != b[i][j * 2 + 1])
                return false;
        }
    }
    return true;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }

    vector<vector<char>> b(n, vector<char>(m * 2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m * 2; j++)
            cin >> b[i][j];
    }

    bool result = IsEyfa(a, b);
    if (result == true)
        cout << "Eyfa" << '\n';
    else
        cout << "Not Eyfa" << '\n';
}