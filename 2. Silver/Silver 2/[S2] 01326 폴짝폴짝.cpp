#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MinJump(int s, int t, vector<int>& stones)
{
    int n = stones.size();

    vector<int> dist(n, INT_MAX);
    dist[s] = 0;

    queue<int> Q;
    Q.push(s);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int d : {-1, +1})
        {
            int v = u;
            while (true)
            {
                v += stones[u] * d;

                if (v < 0 || v >= n)
                    break;
                if (dist[v] != INT_MAX)
                    continue;

                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }

    if (dist[t] == INT_MAX)
        return -1;
    return dist[t];
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> stones(n);
    for (int i = 0; i < n; i++)
        cin >> stones[i];

    int s, t;
    cin >> s >> t;
    s--, t--;

    int result = MinJump(s, t, stones);
    cout << result << '\n';
}