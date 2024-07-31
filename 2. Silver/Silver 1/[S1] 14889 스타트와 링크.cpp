#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int BT(int p, vector<int>& start, vector<int>& link, vector<vector<int>>& s)
{
    int n = s.size();
    int k = start.size();
    int l = link.size();

    if (k > n / 2 || l > n / 2)
        return INT_MAX;

    if (k == n / 2 && l == n / 2)
    {
        int result = 0;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                result += s[start[i]][start[j]];
                result -= s[link[i]][link[j]];
            }
        }
        return abs(result);
    }

    start.push_back(p);
    int pickStart = BT(p + 1, start, link, s);
    start.pop_back();

    link.push_back(p);
    int pickLink = BT(p + 1, start, link, s);
    link.pop_back();

    return min(pickStart, pickLink);
}

int MinDiff(vector<vector<int>>& s)
{
    vector<int> start, link;
    return BT(0, start, link, s);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> s(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> s[i][j];
    }

    int result = MinDiff(s);
    cout << result << '\n';
}