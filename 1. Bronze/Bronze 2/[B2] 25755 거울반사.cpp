#include <iostream>
#include <vector>
#include <map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

map<int, char> rev = {
    {2,'5'},{5,'2'},{1,'1'},{8,'8'}
};

int main()
{
    FastIO;

    char d;
    int n;
    cin >> d >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }

    bool dir = (d == 'D' || d == 'U');
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            int v = dir ? mat[i][j] : mat[n - i - 1][n - j - 1];
            cout << (rev.count(v) ? rev[v] : '?') << ' ';
        }
        cout << '\n';
    }
}