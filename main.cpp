#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<vector<int>> p(n, vector<int>(k));
    vector<pair<int, int>> maxP(k, { 0,0 });
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> p[i][j];
            if (p[i][j] > maxP[j].first)
            {
                maxP[j].first = p[i][j];
                maxP[j].second = 1;
            }
            else if (p[i][j] == maxP[j].first)
                maxP[j].second++;
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        bool can = false;
        for (int j = 0; j < k; j++)
            can |= (p[i][j] == maxP[j].first && maxP[j].second == 1);
        result += can;
    }
    cout << result << '\n';
}