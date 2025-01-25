#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    long long k;
    cin >> n >> k;

    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    int MAX_D = log2(k) + 1;
    vector<vector<int>> pre(MAX_D, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        int d;
        cin >> d;

        pre[0][d] = i;
    }

    for (int j = 1; j < MAX_D; j++)
    {
        for (int i = 1; i <= n; i++)
            pre[j][i] = pre[j - 1][pre[j - 1][i]];
    }

    for (int i = 1; i <= n; i++)
    {
        long long q = k;
        int x = i;

        for (int j = MAX_D - 1; j >= 0; j--)
        {
            if (q & (1LL << j))
            {
                q -= 1LL << j;
                x = pre[j][x];
            }
        }

        cout << s[x] << ' ';
    }
    cout << '\n';
}