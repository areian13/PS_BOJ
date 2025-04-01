#include <iostream>
#include <vector>
#include <cmath>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        int k = log2(m) + 1;
        vector<vector<int>> pre(n + 1, vector<int>(k));
        for (int i = 1; i <= n; i++)
        {
            int p;
            cin >> p;

            pre[p][0] = i;
        }

        for (int j = 1; j < k; j++)
        {
            for (int i = 1; i <= n; i++)
                pre[i][j] = pre[pre[i][j - 1]][j - 1];
        }

        cin.ignore();
        string s;
        getline(cin, s);

        string result = "";
        int t = s.size();
        for (int i = 0; i < t; i++)
        {
            int q = m;
            int x = i + 1;

            for (int j = k - 1; j >= 0; j--)
            {
                if (q >= 1 << j)
                {
                    q -= 1 << j;
                    x = pre[x][j];
                }
            }
            result += s[x - 1];
        }
        cout << result << '\n';
    }
}