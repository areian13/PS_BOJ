#include <iostream>
#include <cmath>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int s = sqrt(n - 1) + 3;
    vector<vector<char>> result(s, vector<char>(s, '.'));
    for (int i = 0; i < s; i++)
    {
        result[i][0] = 'x';
        result[i][s - 1] = 'x';
        result[0][i] = 'x';
        result[s - 1][i] = 'x';
    }

    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
            cout << result[i][j];
        cout << '\n';
    }
}