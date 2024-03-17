#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsHappy(int a, int b, vector<vector<int>>& x)
{
    int n = x.size();

    for (int i = 0; i < n; i++)
    {
        if (x[i][b] > x[a][b])
            return false;
    }

    for (int j = 0; j < n; j++)
    {
        if (x[a][j] > x[a][b])
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;

    vector<vector<int>> x(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> x[i][j];
    }

    string result = IsHappy(a, b, x) ? "HAPPY" : "ANGRY";
    cout << result << '\n';
}