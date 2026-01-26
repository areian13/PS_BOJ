#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Shell(int s, vector<vector<int>>& q)
{
    vector<int> r(3, 0);
    r[s] = 1;

    int result = 0;
    for (auto& p : q)
    {
        swap(r[p[0]], r[p[1]]);
        result += r[p[2]];
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> q(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> q[i][j];
            q[i][j]--;
        }
    }

    int result = 0;
    for (int j = 0; j < 3; j++)
        result = max(result, Shell(j, q));
    cout << result << '\n';
}