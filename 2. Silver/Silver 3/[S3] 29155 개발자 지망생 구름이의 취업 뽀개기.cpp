#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<int, 6> p;
    for (int i = 1; i <= 5; i++)
        cin >> p[i];

    array<vector<int>, 6> goorm;
    for (int i = 0; i < n; i++)
    {
        int k, t;
        cin >> k >> t;

        goorm[k].push_back(t);
    }

    int result = 4 * 60;
    for (int i = 1; i <= 5; i++)
    {
        sort(goorm[i].begin(), goorm[i].end());

        int m = p[i];
        for (int j = 0; j < m; j++)
        {
            result += goorm[i][j];
            if (j > 0)
                result += goorm[i][j] - goorm[i][j - 1];
        }
    }
    cout << result << '\n';
}