#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 200'000;

bool CanParcel(int w, vector<int>& a)
{
    int n = a.size();

    vector<vector<int>> ij(MAX * 2, { -1,-1 });
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            ij[a[i] + a[j]] = { i,j };
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int r = w - (a[i] + a[j]);
            if (r < 0 || r >= MAX * 2) continue;
            if (ij[r][0] == -1) continue;
            if (ij[r][0] != i && ij[r][0] != j && ij[r][1] != i && ij[r][1] != j)
                return true;
        }
    }
    return false;
}

int main()
{
    FastIO;

    int w, n;
    cin >> w >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bool result = CanParcel(w, a);
    cout << (result ? "YES" : "NO") << '\n';
}