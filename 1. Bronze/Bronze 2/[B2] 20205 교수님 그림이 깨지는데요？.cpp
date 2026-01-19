#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<vector<char>> bitmap(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> bitmap[i][j];
    }

    for (int i = 0; i < n * k; i++)
    {
        for (int j = 0; j < n * k; j++)
            cout << bitmap[i / k][j / k] << ' ';
        cout << '\n';
    }
}