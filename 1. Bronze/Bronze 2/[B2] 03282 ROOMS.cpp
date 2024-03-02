#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, g;
    cin >> n >> g;

    vector<int> result(n, 0);
    int room = 0;
    for (int i = 0; i < g; i++)
    {
        int m;
        cin >> m;

        while (m > 0)
        {
            int cnt = min(m, 2 - result[room]);

            result[room] += cnt;
            m -= cnt;
            room = (room + 1) % n;
        }
    }

    for (int i = 0; i < n; i++)
        cout << result[i] << '\n';
}