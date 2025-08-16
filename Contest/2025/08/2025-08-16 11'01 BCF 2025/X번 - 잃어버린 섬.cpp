#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 10'000

bool CanSymmetry(int n, int m, vector<int>& cnt)
{
    if (m & 1)
    {
        int cntH = 0;
        for (int i = 0; i < MAX; i++)
            cntH += cnt[i] & 1;
        return cntH <= n;
    }

    for (int i = 0; i < MAX; i++)
    {
        if (cnt[i] & 1)
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> cnt(MAX, 0);
    for (int i = 0; i < n * m; i++)
    {
        int a;
        cin >> a;

        cnt[a - 1]++;
    }

    bool result = CanSymmetry(n, m, cnt);
    if (result)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}