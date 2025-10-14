#include <bits/stdc++.h>

using namespace std;

void MinMat(vector<int>& a, vector<vector<int>>& m)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int mi = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[mi])
                mi = j;
            m[i][j] = mi;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<vector<int>> am(n, vector<int>(n)), bm(n, vector<int>(n));
    MinMat(a, am);
    MinMat(b, bm);

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int Mi = i;
        for (int j = 0; j < n; j++)
        {
            if (am[i][j] == bm[i][j])
                Mi = j;
        }
        result++;
        i = Mi;
    }
    cout << result << '\n';
}