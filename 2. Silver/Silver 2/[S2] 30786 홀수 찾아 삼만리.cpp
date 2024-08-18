#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> group(2);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        group[(x + y) % 2].push_back(i);
    }

    if (group[0].empty() || group[1].empty())
        cout << "NO" << '\n';
    else
    {
        cout << "YES" << '\n';
        for (int i = 0; i < 2; i++)
        {
            for (int x : group[i])
                cout << x + 1 << ' ';
        }
        cout << '\n';
    }
}