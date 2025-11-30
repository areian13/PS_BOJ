#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void MakeMat(vector<int>& v, vector<vector<int>>& mat)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int mi = i;
        for (int j = i; j < n; j++)
        {
            if (v[j] < v[mi])
                mi = j;
            mat[i][j] = mi;
        }
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<vector<int>> aMat(n, vector<int>(n)), bMat(n, vector<int>(n));
    MakeMat(a, aMat), MakeMat(b, bMat);

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int ni = i;
        for (int j = i; j < n; j++)
        {
            if (aMat[i][j] == bMat[i][j])
                ni = j;
        }
        result++;
        i = ni;
    }
    cout << result << '\n';
}