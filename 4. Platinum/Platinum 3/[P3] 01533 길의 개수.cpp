#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MOD = 1'000'003;

int main()
{
    FastIO;

    int n, s, e, t;
    cin >> n >> s >> e >> t;
    s--, e--;

    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            mat[i][j] = c - '0';
        }
    }


}