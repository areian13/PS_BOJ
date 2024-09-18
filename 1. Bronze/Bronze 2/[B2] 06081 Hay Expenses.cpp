#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, q;
    cin >> n >> q;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    while (q--)
    {
        int s, e;
        cin >> s >> e;
        s--, e--;

        int result = 0;
        for (int i = s; i <= e; i++)
            result += h[i];
        cout << result << '\n';
    }
}