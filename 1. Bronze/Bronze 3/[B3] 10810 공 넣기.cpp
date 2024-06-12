#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> basket(n, 0);
    for (int i = 0; i < m; i++)
    {
        int s, e, v;
        cin >> s >> e >> v;
        s--, e--;

        for (int j = s; j <= e; j++)
            basket[j] = v;
    }
    for (int i = 0; i < n; i++)
        cout << basket[i] << ' ';
    cout << '\n';
}