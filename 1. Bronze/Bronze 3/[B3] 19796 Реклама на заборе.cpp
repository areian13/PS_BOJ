#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int m, n;
    cin >> m >> n;

    vector<bool> isGlued(m + 1, false);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        for (int j = l; j <= r; j++)
            isGlued[j] = true;
    }

    bool isAllGlued = true;
    for (int i = 1; i <= m; i++)
        isAllGlued &= isGlued[i];

    string result = (isAllGlued ? "YES" : "NO");
    cout << result << '\n';
}