#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanSit(int s, int k, vector<char>& seat)
{
    for (int i = s; i < s + k; i++)
    {
        if (seat[i] == '1')
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> seats(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> seats[i][j];
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - k + 1; j++)
            result += CanSit(j, k, seats[i]);
    }
    cout << result << '\n';
}