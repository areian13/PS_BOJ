#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> basket(n);
    for (int i = 0; i < n; i++)
        basket[i] = i + 1;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        swap(basket[a], basket[b]);
    }

    for (int i = 0; i < n; i++)
        cout << basket[i] << ' ';
    cout << '\n';
}