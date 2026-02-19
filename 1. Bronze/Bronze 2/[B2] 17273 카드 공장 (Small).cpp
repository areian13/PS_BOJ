#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> cards(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> cards[i][0] >> cards[i][1];

    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;

        for (int j = 0; j < n; j++)
        {
            if (cards[j][0] <= k)
                swap(cards[j][0], cards[j][1]);
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
        result += cards[i][0];
    cout << result << '\n';
}