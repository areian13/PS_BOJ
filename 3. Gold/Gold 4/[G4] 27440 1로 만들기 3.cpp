#include <iostream>
#include <unordered_map>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long n;
    cin >> n;

    unordered_map<long long, int> dist;
    dist[n] = 0;

    queue<long long> Q;
    Q.push(n);

    while (!Q.empty())
    {
        long long cur = Q.front();
        Q.pop();

        if (cur == 1)
            break;

        if (cur % 3 == 0 && dist[cur / 3] == 0)
        {
            dist[cur / 3] = dist[cur] + 1;
            Q.push(cur / 3);
        }
        if (cur % 2 == 0 && dist[cur / 2] == 0)
        {
            dist[cur / 2] = dist[cur] + 1;
            Q.push(cur / 2);
        }
        if (cur > 1 && dist[cur - 1] == 0)
        {
            dist[cur - 1] = dist[cur] + 1;
            Q.push(cur - 1);
        }
    }
    cout << dist[1] << '\n';
}