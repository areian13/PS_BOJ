#include <iostream>
#include <array>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX_SUSHI 200'000

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    array<priority_queue<int, vector<int>, greater<int>>, MAX_SUSHI> want;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            a--;

            want[a].push(i);
        }
    }

    vector<int> result(n, 0);
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        b--;

        if (!want[b].empty())
        {
            result[want[b].top()]++;
            want[b].pop();
        }
    }

    for (int i = 0; i < n; i++)
        cout << result[i] << ' ';
    cout << '\n';
}