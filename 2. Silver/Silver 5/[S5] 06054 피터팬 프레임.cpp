#include <iostream>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<int> dr = { -2,-1,0,1,2,1,0,-1 };
vector<int> dc = { 0,1,2,1,0,-1,-2,-1 };

int main()
{
    FastIO;

    string s;
    cin >> s;

    int n = s.size();
    vector<vector<char>> result(5, vector<char>(n * 4 + 1, '.'));
    for (int i = 2; i < n * 4 + 1; i += 4)
    {
        result[2][i] = s[i / 4];
        for (int d = 0; d < 8; d++)
        {
            int r = 2 + dr[d];
            int c = i + dc[d];
            result[r][c] = '#';
        }
    }
    for (int i = 10; i < n * 4 + 1; i += 12)
    {
        for (int d = 0; d < 8; d++)
        {
            int r = 2 + dr[d];
            int c = i + dc[d];
            result[r][c] = '*';
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < n * 4 + 1; j++)
            cout << result[i][j];
        cout << '\n';
    }
}