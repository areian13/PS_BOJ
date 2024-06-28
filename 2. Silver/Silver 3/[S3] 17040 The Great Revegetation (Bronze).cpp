#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> cow(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        cow[u].push_back(v);
        cow[v].push_back(u);
    }

    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            bool canPlant = true;
            for (int c : cow[i])
                canPlant &= (result[c] != j);

            if (canPlant)
            {
                result[i] = j;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << result[i];
    cout << '\n';
}