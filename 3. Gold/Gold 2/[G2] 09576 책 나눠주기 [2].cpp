#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> want(m);
        for (int i = 0; i < m; i++)
            cin >> want[i].first >> want[i].second;

        sort(want.begin(), want.end(), [](pair<int, int>& a, pair<int, int>& b)
            {
                if (a.second != b.second)
                    return a.second < b.second;
                return b.first < b.first;
            }
        );

        vector<bool> canGet(n, true);
        int result = 0;
        for (int i = 0; i < m; i++)
        {
            int a = want[i].first - 1;
            int b = want[i].second - 1;

            for (int j = a; j <= b; j++)
            {
                if (canGet[j])
                {
                    canGet[j] = false;
                    result++;
                    break;
                }
            }
        }
        cout << result << '\n';
    }
}