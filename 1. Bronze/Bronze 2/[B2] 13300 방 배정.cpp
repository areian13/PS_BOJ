#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<vector<int>> cnt(2, vector<int>(7, 0));
    for (int i = 0; i < n; i++)
    {
        int s, y;
        cin >> s >> y;
        cnt[s][y]++;
    }

    int result = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j <= 6; j++)
            result += (cnt[i][j] == 0 ? 0 : (cnt[i][j] - 1) / k + 1);
    }
    cout << result << '\n';
}