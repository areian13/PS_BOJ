#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> t(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int k, s, e;
        cin >> k >> s >> e;

        if (t[k] <= s)
        {
            cout << "YES" << '\n';
            t[k] = e;
        }
        else
            cout << "NO" << '\n';
    }
}